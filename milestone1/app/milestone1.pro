#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T14:42:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = milestone1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    encode_widget.cpp \
    decode_widget.cpp \
    overlay_widget.cpp \
    visualcrypt.cpp \
    matrix.cpp

HEADERS += \
        mainwindow.h \
    encode_widget.h \
    decode_widget.h \
    overlay_widget.h \
    visualcrypt.h \
    matrix.h

FORMS += \
        mainwindow.ui \
    encode_widget.ui \
    decode_widget.ui \
    overlay_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
