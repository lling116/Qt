#include "widget.h"
#include <QApplication>
#include "runthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    runThread th1;
     runThread th2;
     th1.start();
     th2.start();

    //需要等待线程结束
     th1.wait();
     th2.wait();
    return a.exec();
}
