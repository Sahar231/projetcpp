//fonction pour ia
#include <QMovie>

#include "ia.h"
#include "ui_ia.h"
#include <QFileDialog>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QTimer>
#include <QGraphicsEllipseItem>  // Ajouté pour QGraphicsEllipseItem
#include <QGraphicsScene>        // Ajouté pour QGraphicsScene
#include <QGraphicsView>         // Ajouté pour QGraphicsView
#include <QWidget>
#include <QPixmap>
#include <QPainter>

//libraries for api
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

ia::ia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ia)
{
    ui->setupUi(this);

    // Appliquer un fond dégradé fluide avec des couleurs pastel modernes
    QString style = R"(
        QWidget {
            background: qlineargradient(
                x1: 0, y1: 0, x2: 1, y2: 1,
                stop: 0 #a7c7e7, stop: 0.5 #b3d9f7, stop: 1 #cce6ff
            );
        }
    )";
    this->setStyleSheet(style);

    // Style moderne pour les boutons avec effets au survol et pression
    QString buttonStyle = R"(
        QPushButton {
            background-color: #b3d9f7; // Couleur bleu pastel clair
            border-radius: 20px;
            padding: 12px;
            font-size: 18px;
            color: white;
            border: none;
            box-shadow: 0px 8px 24px rgba(0, 0, 0, 0.2);
            transition: background-color 0.3s, box-shadow 0.3s ease;
        }

        QPushButton:hover {
            background-color: #99c2e8; // Bleu pastel légèrement plus foncé au survol
            box-shadow: 0px 10px 30px rgba(0, 0, 0, 0.3);
        }

        QPushButton:pressed {
            background-color: #80b3d9; // Couleur encore plus foncée quand le bouton est pressé
            box-shadow: 0px 6px 20px rgba(0, 0, 0, 0.4);
        }
    )";
    ui->btnAjouterImage->setStyleSheet(buttonStyle);
    ui->btnAjouterImage_2->setStyleSheet(buttonStyle);

    // Style moderne pour la zone de texte avec transition fluide
    QString textEditStyle = R"(
        QTextEdit {
            background-color: #e6f2ff; // Bleu pastel clair
            border: 2px solid #a7c7e7; // Bordure en bleu pastel doux
            border-radius: 12px;
            font-size: 16px;
            padding: 15px;
            font-family: "Segoe UI", sans-serif;
            transition: border-color 0.3s ease, background-color 0.3s ease;
        }

        QTextEdit:focus {
            border-color: #99c2e8; // Bordure un peu plus foncée au focus
            background-color: #cce6ff; // Fond un peu plus clair au focus
        }
    )";
    ui->textEdit->setStyleSheet(textEditStyle);

    // Animation d'opacité pour le texte de la zone de texte
    QGraphicsOpacityEffect* opacityEffectText = new QGraphicsOpacityEffect(this);
    ui->textEdit->setGraphicsEffect(opacityEffectText);

    QPropertyAnimation* animationText = new QPropertyAnimation(opacityEffectText, "opacity", this);
    animationText->setDuration(1000);
    animationText->setStartValue(0.0);
    animationText->setEndValue(1.0);
    animationText->start();

    // Appliquer une animation circulaire pour QWidget avec mouvement subtil
    QPropertyAnimation* animationWidget = new QPropertyAnimation(this, "geometry", this);
    animationWidget->setDuration(2000);
    animationWidget->setStartValue(QRect(0, 0, this->width(), this->height()));
    animationWidget->setEndValue(QRect(50, 50, this->width(), this->height()));
    animationWidget->setEasingCurve(QEasingCurve::InOutQuad);
    animationWidget->start();

    // Animation de cercle flottant
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        int x = rand() % this->width();
        int y = rand() % this->height();
        int size = rand() % 50 + 30;

        QGraphicsEllipseItem* circle = new QGraphicsEllipseItem(x, y, size, size);
        circle->setBrush(QBrush(QColor(102, 204, 255, 100)));  // Bleu clair semi-transparent

        QGraphicsScene* scene = new QGraphicsScene(this);
        scene->addItem(circle);

        QGraphicsView* view = new QGraphicsView(scene, this);
        view->setRenderHint(QPainter::Antialiasing);
        view->setFixedSize(size, size);

        QPropertyAnimation* circleAnim = new QPropertyAnimation(view, "geometry", this);
        circleAnim->setDuration(2000);
        circleAnim->setStartValue(view->geometry());
        circleAnim->setEndValue(QRect(rand() % this->width(), rand() % this->height(), size, size));
        circleAnim->setEasingCurve(QEasingCurve::InOutQuad);
        circleAnim->start();
    });
    timer->start(1000);  // Crée un nouveau cercle toutes les secondes
    // Ajout d'un GIF animé en haut à gauche
    QLabel* gifLabel = new QLabel(this);
    gifLabel->setGeometry(10, 10, 200, 200); // position : haut gauche, taille moyenne
    gifLabel->setScaledContents(true); // Redimensionne le GIF pour s’adapter au QLabel

    QMovie* movie = new QMovie("C:/Users/hp/Desktop/2A17/qt/s9/gif.gif");
    if (!movie->isValid()) {
        qDebug() << "Erreur: Impossible de charger le GIF.";
    } else {
        gifLabel->setMovie(movie);
        movie->start();
    }
    /* OLD FUNCTION TO ADD IMAGE
    // Ajouter une image et la centrer dans le label
    connect(ui->btnAjouterImage, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!fileName.isEmpty()) {
            QPixmap image(fileName);
            ui->labelImage->setPixmap(image);
            ui->labelImage->setAlignment(Qt::AlignCenter); // Centrer l'image

            // Générer une description pour l'image (par exemple un texte générique)
            QString description = "⏳ Patienter quelques minutes, le chat 🤖 est en train de générer une description spécifique 📝 pour cette image 🖼️";
            ui->textEdit->setPlainText(description);
        }
    });
*/
    // new testing fct add img
    connect(ui->btnAjouterImage, &QPushButton::clicked, this, [=, this]() {
        QString fileName = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!fileName.isEmpty()) {
            QPixmap image(fileName);
            ui->labelImage->setPixmap(image);
            ui->labelImage->setAlignment(Qt::AlignCenter);

            // Store the path in the class member variable
            imagePath = fileName;

            // always make sure everything is working, before moving to the next step
            //qDebug() << "Chemin de l'image sélectionnée :" << imagePath;



            // Set the description: use this after api response
            QString description = "⏳ Patienter quelques minutes, le chat 🤖 est en train de générer une description spécifique 📝 pour cette image 🖼️.";
            ui->textEdit->setPlainText(description);
        }
    });
    /*
    // Générer un texte basé sur l'image ajoutée
    connect(ui->btnAjouterImage_2, &QPushButton::clicked, this, [=]() {
        QString texte = "Voici un texte généré automatiquement basé sur l'image sélectionnée (exemple).";
        ui->textEdit->setPlainText(texte);

    });
*/
}

// API request
void ia::sendImagePathToAPI(const QString &imagePath) {
    QUrl url("http://localhost:5000/describe");  // Adjust if hosted elsewhere
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ia::handleAPIResponse);

    QByteArray data = imagePath.toUtf8();
    manager->post(request, data);
}

void ia::handleAPIResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString description = reply->readAll();
        ui->textEdit->setPlainText(description);  // Assuming QTextEdit pointer is named this
    } else {
        QString error = "Error: " + reply->errorString();
        ui->textEdit->setPlainText(error);
    }
    reply->deleteLater();
}

void ia::on_btnAjouterImage_2_clicked()
{
    if (!imagePath.isEmpty()) {
        sendImagePathToAPI(imagePath);
    } else {
        ui->textEdit->setPlainText("Aucune image sélectionnée.");
    }
}

ia::~ia() {
    delete ui;
}



