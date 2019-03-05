#include "udpserver.h"
#include<QHostAddress>

udpServer::udpServer(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle("UDP SERVER");
    TimerLabel = new QLabel(tr("计数器："),this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("开始"),this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    connect(StartBtn,SIGNAL(clicked(),
                            this,SLOT(StartBtnClicked()));
    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
                            this,SLOT(timeOut()));

}

udpServer::~udpServer()
{

}

void udpServer::StartBtnClicked()
{
    if(!isStarted)
    {
        StartBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted = true;
    }

    else{
        StartBtn->setText(tr("开始"));
        isStarted  = false;
        timer->stop();
    }
}

void udpServer::timeOut()
{
    QString msg = TextLineEdit->text();
    int length = 0;
    if(msg==""){
        return;
    }

    if((length==udpSocket->writeDatagram(msg.toLatin1(),
        msg.length(),QHostAddress::Broadcast,port))!=msg.length())
    {
        return;
    }
}
