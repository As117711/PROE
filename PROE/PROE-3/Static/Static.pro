#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T03:03:08
#
#-------------------------------------------------

QT       -= gui

TARGET = Static
TEMPLATE = lib
CONFIG += staticlib

SOURCES += static.cpp

HEADERS += static.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
