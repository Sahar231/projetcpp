QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Mainwindow.cpp \
    connection.cpp \
    equipement.cpp \
    historique.cpp \
    main.cpp \
    statistique.cpp

HEADERS += \
    EtatDelegate.h \
    Mainwindow.h \
    connection.h \
    equipement.h \
    historique.h \
    statistique.h

    mainwindow.h

FORMS += \
    Mainwindow.ui \
    historique.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

QT+= sql
CONFIG +=console
QT += printsupport

QT += core gui charts
QT += network
