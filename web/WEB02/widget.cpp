#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
  //  ui->webView->load(QUrl("qrc:/html/web.html"));
}

Widget::~Widget()
{
    delete ui;
}
