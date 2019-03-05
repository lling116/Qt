#include "mutex.h"
#include<QDebug>

Mutex::Mutex(QObject *parent) : QThread(parent)
{

}

void Mutex::run()
{
     qDebug()<<count;
}
