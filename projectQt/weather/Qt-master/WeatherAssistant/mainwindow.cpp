#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDateTime>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QTextCodec>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置无边框透明
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明

    //自定义关闭按钮
    QPushButton *pb = new QPushButton(this);
    pb->setStyleSheet("border-image:url(:/picture/picture/CG10418.png);");
    pb->setGeometry(0,0,40,20);
    connect(pb,SIGNAL(clicked()),this,SLOT(close()));

    //设置lcdnumber组件属性
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->setStyleSheet("color:white;border-image:url();");

    //设置week标签属性
    ui->week->setStyleSheet("font-size:16px;color:white;border-image:url();");

    //设置weather标签属性
    ui->weather->setWordWrap(true);
    ui->weather->setStyleSheet("color:white;border-image:url()");

    //定时器-用于显示当前时间
    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(RefreshTime()));
    timer1->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //当鼠标左键点击时.
    if (event->button() == Qt::LeftButton)
    {
        m_move = true;
        //记录鼠标的世界坐标.
        m_startPoint = event->globalPos();
        //记录窗体的世界坐标.
        m_windowPoint = this->frameGeometry().topLeft();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置.
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可.
        this->move(m_windowPoint + relativePos);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态.
        m_move = false;
    }
}

void MainWindow::RefreshTime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    QString current_week = current_date_time.toString("dddd");
    ui->lcdNumber->display(current_date);
    ui->week->setText(current_week);

}

void MainWindow::RefreshWeather()
{
    manage = new QNetworkAccessManager(this);
    QNetworkRequest network_request;
    /*设置发送数据*/
    network_request.setUrl(QUrl("http://wthrcdn.etouch.cn/weather_mini?city=苏州"));
    network_request.setHeader(QNetworkRequest::UserAgentHeader,"RT-Thread ART");
    connect(manage,SIGNAL(finished(QNetworkReply *)),this,SLOT(replyFinished(QNetworkReply*)));
    /*发送get网络请求*/
    manage->get(network_request);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray response = reply->readAll();
    WeatherDataAnalyze(response);//解析数据
    reply->deleteLater();
}

void MainWindow::WeatherDataAnalyze(QByteArray &WeaDat)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(WeaDat,&err);

    QJsonObject root = doc.object();
    QString CityName = root.value("data").toObject().value("city").toString();
    QString AQI = "空气污染指数" + root.value("data").toObject().value("aqi").toString();//空气污染指数
    QString Temp = root.value("data").toObject().value("wendu").toString()+"℃";//当前温度
    QString Tips = root.value("data").toObject().value("ganmao").toString();//提醒

    QJsonValue Forecast = root.value("data").toObject().value("forecast").toArray().at(0);
    QString Weather = Forecast.toObject().value("type").toString();

    QString weatherData = CityName+'\n'+Temp+"  "+Weather+'\n'+AQI+'\n'+Tips;
    ui->weather->setText(weatherData);

}


