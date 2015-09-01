#-------------------------------------------------
#
# Project created by QtCreator 2015-06-10T18:24:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROE3
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    building.cpp \
    addnodeqt.cpp \
    removenodeqt.cpp \
    displaynodeqt.cpp \
    simpleprocessing.cpp

HEADERS  += mainwindow.h \
    list.h \
    building.h \
    addnodeqt.h \
    removenodeqt.h \
    displaynodeqt.h \
    simpleprocessing.h

FORMS    += mainwindow.ui \
    addnodeqt.ui \
    removenodeqt.ui \
    displaynodeqt.ui
