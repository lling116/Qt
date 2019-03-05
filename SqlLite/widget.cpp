#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //打印Qt支持的数据库驱动
    qDebug() << QSqlDatabase::drivers();

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

    query.prepare("insert into student(name, age, score) values(?, ?, ?)");
    //给字段设置内容 list
    QVariantList nameList;
    nameList << "xiaoming" << "xiaolong" << "xiaojiang";
    QVariantList ageList;
    ageList << 11 << 22 << 33;
    QVariantList scoreList;
    scoreList << 59 << 69 << 79;
    //给字段绑定相应的值 按顺序绑定
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    //执行预处理命令
    query.execBatch();

    query.exec("select * from student");

    while(query.next()) //一行一行遍历
    {
        //取出当前行的内容
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value("age").toInt()
                 << query.value("score").toInt();
    }



}

Widget::~Widget()
{
    delete ui;
}
