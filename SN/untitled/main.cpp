#include "widget.h"
#include <QApplication>
void setStyleSheet()
{
    QFile qss("../style/styleSheet.css");
    qss.open(QIODevice::ReadOnly);
    QString css = qss.readAll();
    qApp->setStyleSheet(css);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setStyleSheet();
    Widget w;
    w.setFixedSize(535,385);
    w.show();

    return a.exec();
}
