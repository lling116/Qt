#include "sqlwidget.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include<QDateTime>

sqlWidget::sqlWidget(QWidget *parent) :
    QWidget(parent)
{
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
    //create table if not exists nodetype(id integer PRIMARY KEY autoincrement,type int)
    query.exec("create table if not exists invInfo(id int primary key, time varchar(255), place varchar(255));");

    query.prepare("insert into student(time, place) values(?, ?, ?)");
    //给字段设置内容 list
    QVariantList nameList;
    nameList << "xiaoming" << "xiaolong" << "xiaojiang";
    QVariantList ageList;
    ageList << 11 << 22 << 33;
    QVariantList scoreList;
    scoreList << 60 << 50 << 79;
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
