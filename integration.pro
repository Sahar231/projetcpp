QT       += core gui \

    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Modules optionnels : on teste leur disponibilité pour éviter les erreurs
contains(QT_CONFIG, serialport) {
    QT += serialport
    message("✅ QtSerialPort module activé.")
} else {
    message("❌ QtSerialPort non disponible.")
}

contains(QT_CONFIG, texttospeech) {
    QT += texttospeech
    message("✅ QtTextToSpeech module activé.")
} else {
    message("❌ QtTextToSpeech non disponible.")
}

win32:contains(QT_CONFIG, axcontainer) {
    QT += axcontainer
    message("✅ ActiveQt (axcontainer) activé.")
} else:win32 {
    message("❌ axcontainer non disponible ou incompatible avec le compilateur.")
}


SOURCES += \
    ard.cpp \
    arduino.cpp \
    chat.cpp \
    connection.cpp \
    employe.cpp \
    equip.cpp \
    equipements.cpp \
    form.cpp \
    formation.cpp \
    historique.cpp \
    ia.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    patie.cpp \
    patient.cpp \
    projet.cpp \
    recherche.cpp \
    serialcommunication.cpp \
    stati.cpp \
    statistique.cpp \
    user.cpp \
    vaccin.cpp

HEADERS += \
    EtatDelegate.h \
    ard.h \
    arduino.h \
    chat.h \
    connection.h \
    employe.h \
    equip.h \
    equipements.h \
    form.h \
    formation.h \
    historique.h \
    ia.h \
    login.h \
    mainwindow.h \
    menu.h \
    patie.h \
    patient.h \
    projet.h \
    recherche.h \
    serialcommunication.h \
    stati.h \
    statistique.h \
    user.h \
    vaccin.h \
    webaxwidget.h



FORMS += \
    chat.ui \
    equip.ui \
    form.ui \
    historique.ui \
    ia.ui \
    login.ui \
    mainwindow.ui \
    menu.ui \
    patie.ui \
    projet.ui \
    stati.ui \
    statistique.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
    INCLUDEPATH += $$PWD/qzxing
    include(qzxing/QZXing.pri)


QT+= sql
CONFIG +=console
QT += printsupport

QT += core gui charts
QT += network
QT += multimedia
QT += serialport
QT +=axcontainer
QT +=multimediawidgets
DISTFILES += translations.json
