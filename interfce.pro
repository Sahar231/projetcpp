QT       += core gui
QT += sql
QT += printsupport
QT += charts
QT += charts
QT += network
QT += core gui network





greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    ia.cpp \
    main.cpp \
    mainwindow.cpp \
    vaccin.cpp \


HEADERS += \
    connection.h \
    ia.h \
    mainwindow.h \
    vaccin.h \


FORMS += \
    ia.ui \
 ia.ui \
    mainwindow.ui

RESOURCES += \
    res.qrc
    # === QR Code Support via QZXing ===
    INCLUDEPATH += $$PWD/qzxing
    include(qzxing/QZXing.pri)
