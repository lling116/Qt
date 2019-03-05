#include "mywidget.h"
#include "ui_mywidget.h"
#include <QUrl>
#include <QFile>
#include<QWebFrame>
#include<QDebug>


//#include<QWebEngineView> Qt5.6 之后的版本

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    m_pExternal = new External();

    mTimer = new QTimer(this);
    mTimer->start(1000);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(update()));


    ui->webView->load(QUrl("qrc:/keyao/keyao/ky5000.html"));
    connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared())
            ,this,SLOT(AddJavascriptWindowObject()));
}

myWidget::~myWidget()
{
    delete ui;
}

void myWidget::AddJavascriptWindowObject()
{
     ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("mywebkit", this);
}

void myWidget::on_pushButton_clicked()
{
    QString strVal = QString("onMsgFromQt(\"%1\");").arg("45661");
    ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
}

void myWidget::onCall(QString strText)
{
         str = strText;


}

void myWidget::update()
{
    QString strVal = QString("onMsgFromQt(\"%1\");").arg("45661");
    ui->webView->page()->mainFrame()->evaluateJavaScript(strVal);
    if(str.length()!=0)
    {
        qDebug()<<str;
    }

}
