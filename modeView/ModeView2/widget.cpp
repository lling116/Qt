#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    itemModel= new QStandardItemModel(20,5);
    itemModel->setHorizontalHeaderLabels(QStringList()<<"name"<<"class"<<"Age"<<"Sex"<<"Gride");
    ui->tableView->setModel(itemModel);
    ui->tableView_2->setModel(itemModel);

    ui->tableView->horizontalHeader()->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView_2->horizontalHeader()->setAlternatingRowColors(true);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_clearBtn_clicked()
{
    int rowCount = itemModel->rowCount();
    itemModel->
    for(int r = rowCount;r>0;--r)
    {
       itemModel->removeRow(r);
    }

    for(int r = 0; r < rowCount;r++)
    {
        itemModel->insertRow(r);
    }
}
