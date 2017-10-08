#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T23:34:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = organizer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Current.cpp \
    AnimatedSplitter.cpp

HEADERS  += mainwindow.h \
    globals.h \
    Current.h \
    AnimatedSplitter.h

FORMS    += mainwindow.ui
