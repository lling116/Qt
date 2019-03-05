#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QBoxLayout>
#include<QTimer>
#include<QUdpSocket>

class udpServer : public QDialog
{
    Q_OBJECT

public:
    udpServer(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~udpServer();

private:
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;

    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
public slots:
    void StartBtnClicked();
    void timeOut();

};

#endif // UDPSERVER_H
