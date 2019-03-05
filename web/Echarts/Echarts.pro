#-------------------------------------------------
#
# Project created by QtCreator 2019-03-02T10:44:14
#
#-------------------------------------------------

QT       += core gui
QT += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Echarts
TEMPLATE = app


SOURCES += main.cpp\
        webwidget.cpp

HEADERS  += webwidget.h

FORMS    += webwidget.ui

RESOURCES += \
    web.qrc
