#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T14:23:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qextserialbase.cpp \
    win_qextserialport.cpp

HEADERS  += widget.h \
    qextserialbase.h \
    win_qextserialport.h

FORMS    += widget.ui
