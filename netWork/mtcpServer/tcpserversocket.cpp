#include "tcpserversocket.h"

tcpserversocket::tcpserversocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dateReceivved()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDiscconnected()));
}

void tcpserversocket::dateReceivved()
{
    while (bytesAvailable()>0)
    {
        //bytesAvailabl()当前套接字读取 数据的字节数
        int length= bytesAvailable();
        char buf[1024];
        //把当前套接字读取的数据放到buf里
        read(buf,length);

        QString msg = buf;
        emit updateClients(msg,length);
    }
}

void tcpserversocket::slotDiscconnected()
{
    emit disconnected(this->socketDescriptor());
}
