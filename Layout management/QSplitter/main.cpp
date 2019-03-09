#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong18030",12);
    a.setFont(font);
    Widget w;
   // w.show();

    return a.exec();
}
