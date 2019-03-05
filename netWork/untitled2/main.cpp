#include "udpserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpServer w;
    w.show();

    return a.exec();
}
