#include "webwidget.h"
#include "ui_webwidget.h"

WebWidget::WebWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebWidget)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("qrc:/html/web.html"));
}

WebWidget::~WebWidget()
{
    delete ui;
}
