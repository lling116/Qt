#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H

#include <QObject>
#include<QTcpSocket>

class tcpserversocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcpserversocket(QObject *parent = nullptr);

signals:
    void updateClients(QString,int);
    void disconnected(int);

public slots:
    void  dateReceivved();
    void slotDiscconnected();

};

#endif // TCPSERVERSOCKET_H
