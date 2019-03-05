#include "info.h"
#include "ui_info.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include<QSqlQuery>
#include<QDateTime>

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);

   setWindowTitle("记录");
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
      query.exec("create table student(id int primary key, name varchar(50), place varchar(255), time varchar(50));");
        //设置模型
        model = new QSqlTableModel(this);
        model->setTable("student");//制定使用哪个表

        //把model放在view
        ui->tableView->setModel(model);

        //显示model里的数据
        model->select();

        model->setHeaderData(0, Qt::Horizontal, "SN");

        //设置model的编辑模式，手动提交修改
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);


        //设置view中的数据库不允许修改
        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

info::~info()
{
    delete ui;
}

QString info::getLoaclTime()
{
    QDateTime mTime = QDateTime::currentDateTime();
    QString sTime = mTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    return sTime;
}

void info::on_pushButton_clicked()
{
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //添加空记录
    QSqlRecord record = model->record(); //获取空记录
    QDateTime mTime = QDateTime::currentDateTime();
    QString sTime = mTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    record.setValue("time",sTime);
    int row = model->rowCount();
    model->insertRecord(row, record);

}

void info::on_onBtn_clicked()
{

    model->submitAll(); //提交动作
}

void info::on_cancelBtn_clicked()
{
    model->revertAll(); //取消所用动作
    model->submitAll(); //提交动作
}

void info::on_delBtn_clicked()
{
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
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

//查找
void info::on_pushButton_2_clicked()
{

    QString idStr = ui->lineEdit->text();
    if(!idStr.length())
    {
        //当为空查找所有的
        model->setFilter("");
        model->select();
        return;
    }

    QString str = QString("id = '%1'").arg(idStr);

    model->setFilter(str);
    model->select();
}

void info::insertSN(QString snInf)
{
    //设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    QSqlRecord record = model->record(); //获取空记录
    record.setValue("id",snInf);
    QDateTime mTime = QDateTime::currentDateTime();
    QString sTime = mTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    record.setValue("time",sTime);
    int row = model->rowCount();
    model->insertRecord(row, record);
     model->submitAll(); //提交动作
}

void info::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
    {
        model->setFilter("");
        model->select();
    }
}
