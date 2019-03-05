#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include<QSqlQuery>
#include<QDateTime>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //添加Sqlite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("../info.db");

    //打开数据库
    if( !db.open() ) //数据库打开失败
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query;
    query.exec("create table student(id int primary key, name varchar(255), age int, score int);");
    //设置模型
    model = new QSqlTableModel(this);
    model->setTable("student");//制定使用哪个表

    //把model放在view
    ui->tableView->setModel(model);

    //显示model里的数据
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "学号");

    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //设置view中的数据库不允许修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonAdd_clicked()
{
    //添加空记录
    QSqlRecord record = model->record(); //获取空记录
    //获取行号
    int row = model->rowCount();
    model->insertRecord(row, record);
    model->data(row,Qt::TextAlignmentRole)


}

void Widget::on_buttonSure_clicked()
{
    model->submitAll(); //提交动作
}

void Widget::on_buttonCancel_clicked()
{
    model->revertAll(); //取消所用动作
    model->submitAll(); //提交动作
}

void Widget::on_buttonDel_clicked()
{
    //获取选中的模型
    QItemSelectionModel *sModel =ui->tableView->selectionModel();
    //取出模型中的索引
    QModelIndexList list = sModel->selectedRows();
    //删除所有选中的行
    for(int i = 0; i < list.size(); i++)
    {
        model->removeRow( list.at(i).row() );
    }

}

void Widget::on_buttonFind_clicked()
{
    QString name = ui->lineEdit->text();
    QString str = QString("name = '%1'").arg(name);

    model->setFilter(str);
    model->select();

}
