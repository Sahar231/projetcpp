#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QSslSocket>
#include <QSqlQuery>
#include<QVBoxLayout>
#include<QLabel>
#include"user.h"
#include<QAccessibleWidget>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->mdp->setEchoMode(QLineEdit::Password);
    QPalette palette;
    QPixmap pixmap("c:/Users/Sahar/Bureau/project/integration/back55.jpg");
    palette.setBrush(QPalette::Window, pixmap);
    ui->widget->setPalette(palette);
    ui->widget->setAutoFillBackground(true);

    // Créer le label avec un lien "Mot de passe oublié ?"

}

login::~login()
{
    delete ui;
}

bool login::loginEmploye(QString email, QString mdp)
{
    email = email.trimmed();

    // Vérification que l'email n'est pas vide
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email.");
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT id_employe FROM employe WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            QString id_employe_from_db = query.value(0).toString();
            if (mdp == id_employe_from_db) {
                return true; // Connexion réussie
            }
        }
    }

    return false; // Adresse non trouvée ou mot de passe incorrect
}

// In your login dialog, you can handle the validation like this:

void login::on_buttonBox_accepted()
{
    QString adresse = ui->adresse->text();
    QString mdp = ui->mdp->text();

    // Validate that the fields are not empty
    if (adresse.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre adresse email et votre mot de passe.");
        reject();
        return;
    }

    // Disable the buttons temporarily while we are validating
    ui->buttonBox->setEnabled(false);

    // Validate email and password with the database or authentication logic
    if (loginEmploye(adresse, mdp)) {
        // If login is successful
        QMessageBox::information(this, "Connexion", "Connexion réussie !");
        accept();  // Close the login dialog and proceed
    } else {
        // If login fails
        QMessageBox::warning(this, "Connexion", "Adresse ou mot de passe incorrect.");

        // Clear the password field for the user to retry
        ui->mdp->clear();

        // Re-enable the button to allow the user to try again
        ui->buttonBox->setEnabled(true);
        reject();
    }
}



QString login::getEmployeId(QString email)
{
    QSqlQuery query;
    query.prepare("SELECT id_employe FROM employe WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toString(); // Return the employee ID
        }
    }

    return ""; // Return empty string if not found
}

void login::sendEmail(QString employeId)
{
    QString serveur = "smtp.gmail.com";
    int port = 587; // Port pour SMTP avec STARTTLS

    // Informations de l'expéditeur et du destinataire
    QString expediteur = "islemyousfi189@gmail.com";
    QString destinataire = ui->adresse->text();

    QString subject = "Recuperation de mot de passe oublié ";

    // Détails du message
    QString corps = "Votre mot de passe est : "+employeId  ;

    // Connexion au serveur SMTP
    QSslSocket socket;
    socket.connectToHost(serveur, port);
    if (!socket.waitForConnected()) {
        qDebug() << "Échec de connexion au serveur SMTP:" << socket.errorString();
        return;
    }

    // Attente de la réponse du serveur
    if (!socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse initiale du serveur

    // Envoi de la commande EHLO
    socket.write("EHLO localhost\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (EHLO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après EHLO

    // Envoi de la commande STARTTLS
    socket.write("STARTTLS\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (STARTTLS):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après STARTTLS

    // Démarrer le chiffrement
    socket.startClientEncryption();
    if (!socket.waitForEncrypted()) {
        qDebug() << "Échec du chiffrement:" << socket.errorString();
        return;
    }

    // Envoi de la commande AUTH LOGIN
    socket.write("AUTH LOGIN\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (AUTH LOGIN):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après AUTH LOGIN

    // Envoi du nom d'utilisateur encodé en Base64
    socket.write(QByteArray().append(expediteur.toUtf8()).toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (Nom d'utilisateur):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du nom d'utilisateur

    // Envoi du mot de passe encodé en Base64
    socket.write(QByteArray().append("shwn uavw qtsz jmqj").toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec de l'authentification SMTP (Mot de passe):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du mot de passe

    // Envoi de la commande MAIL FROM
    socket.write("MAIL FROM:<" + expediteur.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (MAIL FROM):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après MAIL FROM

    // Envoi de la commande RCPT TO
    socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (RCPT TO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après RCPT TO

    // Envoi de la commande DATA
    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (DATA):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après DATA

    // Envoi des en-têtes et du corps du message
    socket.write("From: " + expediteur.toUtf8() + "\r\n");
    socket.write("To: " + destinataire.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("\r\n");
    socket.write(corps.toUtf8() + "\r\n");
    socket.write(".\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec d'envoi des données du mail:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi des données du mail

    // Envoi de la commande QUIT
    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Échec d'envoi de la commande QUIT:" << socket.errorString();
        return;
    }

    // Fermeture de la connexion
    socket.close();
    QMessageBox::information(this, "Succès", "L'email a été envoyé avec succès à " + destinataire);}





void login::on_pushButton_clicked()
{
    QString adresse = ui->adresse->text();
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email.");
        return;  // Exit the function if the email is empty
    }
    if (getEmployeId(adresse).isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'adresse email n'existe pas dans la base de données.");
        return;  // Exit the function if the email does not exist
    }

    QString employeId = getEmployeId(adresse);
    sendEmail(employeId);  // Send email with the retrieved employee ID
}
