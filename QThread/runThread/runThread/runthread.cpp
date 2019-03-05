#include "runthread.h"

runThread::runThread(QObject *parent) : QThread(parent)
{

}

void runThread::run()
{
     for( int count = 0; count < 20; count++ )
     {
         sleep( 1 );
         qDebug( "Ping!" );
     }
}
