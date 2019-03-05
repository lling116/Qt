#include "widget.h"
#include <QApplication>
#include<QDebug>
#include<QThread>
#include"myobject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   qDebug() << QString("main thread id:") << QThread::currentThreadId();

    MyObject m_object;
    QThread thread;
   // m_object.moveToThread(&thread);

    QObject::connect(&thread, SIGNAL(started()), &m_object, SLOT(start()),Qt::QueuedConnection);
    thread.start();
    return a.exec();
}
