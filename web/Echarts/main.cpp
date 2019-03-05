#include "webwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebWidget w;
    w.show();

    return a.exec();
}
