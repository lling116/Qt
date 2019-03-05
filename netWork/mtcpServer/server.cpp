#include "server.h"

server:: server(QObject *parent,int port):QTcpServer(parent)
{
    //指定端口对任意地址监听
    listen(QHostAddress::Any,port);
}

void server::incomingConnection(int socketDescriptor)
{
   tcpserversocket* tcpserverSocket = new tcpserversocket(this);
   connect(tcpserverSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
   connect(tcpserverSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));
   tcpserverSocket->setSocketDescriptor(socketDescriptor);
   tcpserversocketList.append(tcpserverSocket);

}
