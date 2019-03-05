#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::start()
{
    qDebug() << QString("my object thread id:") << QThread::currentThreadId();
}
