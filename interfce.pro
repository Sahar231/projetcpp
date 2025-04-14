QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT       += core gui sql
QT       += core gui charts
QT       += charts
QT       += multimedia
QT       += printsupport
QT       += axcontainer
QT       += network
QT       += serialport
QT       += texttospeech
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    connection.cpp \
    employe.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp


HEADERS += \
    chat.h \
    connection.h \
    employe.h \
    login.h \
    mainwindow.h


FORMS += \
    chat.ui \
    login.ui \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
