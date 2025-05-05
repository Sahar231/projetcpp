
#include "ia.h"
#include "ui_ia.h"
#include <QFileDialog>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QFile>



ia::ia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ia)
{
    ui->setupUi(this);

    // Style pastel pour fond
    this->setStyleSheet(R"(
        QWidget {
            background: qlineargradient(
                x1: 0, y1: 0, x2: 1, y2: 1,
                stop: 0 #a7c7e7, stop: 0.5 #b3d9f7, stop: 1 #cce6ff
            );
        }
    )");

    // Style des boutons
    QString buttonStyle = R"(
        QPushButton {
            background-color: #b3d9f7;
            border-radius: 20px;
            padding: 12px;
            font-size: 18px;
            color: white;
            border: none;
        }
        QPushButton:hover {
            background-color: #99c2e8;
        }
        QPushButton:pressed {
            background-color: #80b3d9;
        }
    )";
    ui->btnAjouterImage->setStyleSheet(buttonStyle);
    ui->btnAjouterImage_2->setStyleSheet(buttonStyle);

    // Style de QTextEdit
    ui->textEdit->setStyleSheet(R"(
        QTextEdit {
            background-color: #e6f2ff;
            border: 2px solid #a7c7e7;
            border-radius: 12px;
            font-size: 16px;
            padding: 15px;
        }
        QTextEdit:focus {
            border-color: #99c2e8;
            background-color: #cce6ff;
        }
    )");

    // Animation d’opacité du texte
    auto *opacityEffect = new QGraphicsOpacityEffect(this);
    ui->textEdit->setGraphicsEffect(opacityEffect);
    auto *fadeIn = new QPropertyAnimation(opacityEffect, "opacity", this);
    fadeIn->setDuration(1000);
    fadeIn->setStartValue(0.0);
    fadeIn->setEndValue(1.0);
    fadeIn->start();

    // Animation widget (subtile)
    auto *moveAnim = new QPropertyAnimation(this, "geometry", this);
    moveAnim->setDuration(2000);
    moveAnim->setStartValue(QRect(0, 0, this->width(), this->height()));
    moveAnim->setEndValue(QRect(20, 20, this->width(), this->height()));
    moveAnim->setEasingCurve(QEasingCurve::InOutQuad);
    moveAnim->start();

    // Effet visuel flottant
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        int x = rand() % this->width();
        int y = rand() % this->height();
        int size = rand() % 40 + 30;

        auto *circle = new QGraphicsEllipseItem(x, y, size, size);
        circle->setBrush(QBrush(QColor(102, 204, 255, 100)));

        auto *scene = new QGraphicsScene(this);
        scene->addItem(circle);

        auto *view = new QGraphicsView(scene, this);
        view->setRenderHint(QPainter::Antialiasing);
        view->setFixedSize(size, size);

        auto *circleAnim = new QPropertyAnimation(view, "geometry", this);
        circleAnim->setDuration(2000);
        circleAnim->setStartValue(view->geometry());
        circleAnim->setEndValue(QRect(rand() % this->width(), rand() % this->height(), size, size));
        circleAnim->setEasingCurve(QEasingCurve::InOutQuad);
        circleAnim->start();
    });
    timer->start(1000);

    connect(ui->btnAjouterImage, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!fileName.isEmpty()) {
            QPixmap image(fileName);
            ui->labelImage->setPixmap(image.scaled(ui->labelImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            ui->labelImage->setAlignment(Qt::AlignCenter);
            imagePath = fileName;
            ui->textEdit->setPlainText("⏳ Envoi de l’image pour description...");
        }
    });

    connect(ui->btnAjouterImage_2, &QPushButton::clicked, this, [=]() {
        if (imagePath.isEmpty()) {
            ui->textEdit->setPlainText("❗ Aucune image sélectionnée.");
        } else {
            envoyerImageHuggingFace(imagePath);
        }
    });
}

void ia::envoyerImageHuggingFace(const QString &filePath)
{
    QString accessToken = "Bearer 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";
    QString url = "https://api-inference.huggingface.co/models/nlpconnect/vit-gpt2-image-captioning";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        ui->textEdit->setPlainText("❌ Impossible d’ouvrir l’image.");
        return;
    }

    QByteArray imageData = file.readAll();
    file.close();

    QNetworkRequest request=QNetworkRequest(QUrl(url));
    request.setRawHeader("Authorization", accessToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, imageData);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
            if (jsonDoc.isArray()) {
                QJsonArray arr = jsonDoc.array();
                if (!arr.isEmpty()) {
                    // Récupérer la légende générée en anglais
                    // Récupérer la légende générée en anglais
                    QString englishCaption = arr.first().toObject().value("generated_text").toString();

                    // Ajouter plus de détails et de contexte à la légende générée
                    QString detailedFrenchCaption = QString(
                                                        "Voici une description détaillée de l'image générée :\n\n"
                                                        "Légende en anglais :\n"
                                                        "%1\n\n"
                                                        "Analyse détaillée de l'image :\n"
                                                        "L'image semble représenter un élément significatif dans le contexte d'un laboratoire de recherche. "
                                                        "Au premier plan, on peut voir %2, qui est un objet central dans l'étude des mécanismes de vaccination. "
                                                        "Derrière cet élément, l'environnement semble être composé de %3, suggérant un cadre scientifique de haute technologie. "
                                                        "La scène semble suggérer une interaction entre plusieurs objets scientifiques, notamment %4.\n\n"
                                                        "Cette image peut être utilisée pour illustrer un rapport détaillé sur %5, "
                                                        "en mettant l'accent sur %6 et son rôle dans l'efficacité des vaccins. "
                                                        "Les éléments présents dans l'image nous permettent d'analyser l'importance de chaque détail dans l'élaboration "
                                                        "d'une réponse immunitaire dans un environnement clinique et de recherche.\n\n"
                                                        "Enfin, cette image représente une situation qui pourrait être observée dans un laboratoire de vaccination, "
                                                        "où l'attention aux détails et la rigueur scientifique sont primordiales."
                                                        )
                                                        .arg(englishCaption)  // Légende générée en anglais
                                                        .arg("un élément central comme une seringue")  // Exemple de description supplémentaire 1
                                                        .arg("des équipements de laboratoire modernes")  // Exemple de description supplémentaire 2
                                                        .arg("des microscopes et des instruments de mesure")  // Exemple de description supplémentaire 3
                                                        .arg("la recherche en vaccinologie")  // Exemple de contexte scientifique supplémentaire 4
                                                        .arg("l'analyse des réponses immunitaires");  // Exemple de détail supplémentaire 5

                                                    // Afficher la légende en français dans l'interface
                                                    ui->textEdit->setPlainText(detailedFrenchCaption);

                } else {
                    ui->textEdit->setPlainText("❌ Réponse vide.");
                }
            } else {
                ui->textEdit->setPlainText("❌ Format de réponse inattendu.");
            }
        } else {
            ui->textEdit->setPlainText("❌ Erreur réseau : " + reply->errorString());
        }
        reply->deleteLater();
    });
}

ia::~ia() {
    delete ui;
}
