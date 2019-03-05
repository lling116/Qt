#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T14:23:02
#
#-------------------------------------------------

QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qextserialbase.cpp \
    win_qextserialport.cpp \
    info.cpp

HEADERS  += widget.h \
    qextserialbase.h \
    win_qextserialport.h \
    info.h

FORMS    += widget.ui \
    info.ui
