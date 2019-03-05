#include "widget.h"
#include <QApplication>
#include "mutex.h"


int count = 0;
void debugCount(){
    count++;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mutex m;
    m.start();
    return a.exec();
}
