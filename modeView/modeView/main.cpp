 #include "widget.h"
#include <QApplication>
#include<QTreeView>
#include<QListView>
#include<QSplitter>
#include<QFileSystemModel>
#include<QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //  Widget w;
  //  w.show();

    QSplitter *spliter = new QSplitter;
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    QTreeView *treeView = new QTreeView(spliter);
    treeView->setModel(model);
    QListView *listView = new QListView(spliter);
    listView->setModel(model);
    spliter->show();

    return a.exec();
}
