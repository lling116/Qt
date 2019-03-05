#ifndef SERVER_H
#define SERVER_H

#include<QTcpServer>
#include<QObject>
#include "tcpserversocket.h"

class server : public QTcpServer
{
    Q_OBJECT
public:
    server(QObject *parent=0,int port=0);
    //保存与每个客户端连接的tcpClientSocket
    QList<tcpserversocket*> tcpserversocketList;

signals:
    void updateServer(QString,int);

public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);

protected:
    void incomingConnection(int socketDescriptor);

};

#endif // SERVER_H
