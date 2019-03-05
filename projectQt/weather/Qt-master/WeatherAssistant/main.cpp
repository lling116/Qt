#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget* desktopWidget = QApplication::desktop();
    MainWindow w;
    w.RefreshWeather();
    w.setGeometry(desktopWidget->width()-w.width(),0,w.width(),w.height());
    w.show();

    return a.exec();
}
