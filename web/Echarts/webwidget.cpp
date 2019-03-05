#include "webwidget.h"
#include "ui_webwidget.h"

WebWidget::WebWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebWidget)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("qrc:/html/QtWeb/echarts.html"));
    //ui->webView->load(QUrl("qrc:/keyao/keyao/web.html"));
}

WebWidget::~WebWidget()
{
    delete ui;
}
