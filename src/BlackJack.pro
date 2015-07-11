#-------------------------------------------------
#
# Project created by QtCreator 2015-07-09T15:19:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackJack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playwindow.cpp

HEADERS  += mainwindow.h \
    playwindow.h

FORMS    += mainwindow.ui \
    playwindow.ui

DISTFILES +=

RESOURCES += \
    images.qrc
