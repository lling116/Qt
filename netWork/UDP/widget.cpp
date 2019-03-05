#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);

    //绑定
    //udpSocket->bind(8888);
    udpSocket->bind(QHostAddress::AnyIPv4, 8888);

    //加入某个组播
    //组播地址是D类地址
    udpSocket->joinMulticastGroup( QHostAddress("224.0.0.2") );
    //udpSocket->leaveMulticastGroup(); //退出组播

    setWindowTitle("服务器端口为：8888");

    //当对方成功发送数据过来
    //自动触发 readyRead()
    connect(udpSocket, &QUdpSocket::readyRead, this, &Widget::dealMsg);
}

void Widget::dealMsg()
{
    //读取对方发送的内容
    char buf[1024] = {0};
    QHostAddress cliAddr; //对方地址
    quint16 port;    //对方端口
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddr, &port);
    if(len > 0)
    {
        //格式化 [192.68.2.2:8888]aaaa
        QString str = QString("[%1:%2] %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        //给编辑区设置内容
        ui->textEdit->setText(str);
    }


}

Widget::~Widget()
{
    delete ui;
}

//发送按钮
void Widget::on_buttonSend_clicked()
{
    //先获取对方的IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();

    //给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(), QHostAddress(ip), port);


}
