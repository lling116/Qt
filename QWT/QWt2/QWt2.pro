#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T15:55:51
#
#-------------------------------------------------

QT       += core gui
CONFIG += qwt
DEFINES +=QT_DLL_QWT_DLL
LIBS +=  -L"E:\JiJiDown\Download\react\build-qwt-Desktop_Qt_5_9_6_MinGW_32bit-Debug\lib" -lqwtd
LIBS +=  -L"E:\JiJiDown\Download\react\build-qwt-Desktop_Qt_5_9_6_MinGW_32bit-Debug\lib" -lqwt
INCLUDEPATH += D:\Qts\Qt5.9.6\5.9.6\mingw53_32\include\QWT
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWt2
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


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h
