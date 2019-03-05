#include "widget.h"
#include <QApplication>
#include<QFile>
/*
 * 1.添加学校
 * 2.添加班级
 * 3.右键弹出菜单
 * 4.删除学校删除班级
 *
*/
//设置样式表
void setStyleSheet()
{
    QFile qss("../style/styleSheet.css");
    qss.open(QIODevice::ReadOnly);
    QString css = qss.readAll();
    qApp->setStyleSheet(css);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setStyleSheet();
    Widget w;
    w.show();

    return a.exec();
}
