#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMenu>
#include<QAction>
#include<QTreeWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
   void initTreeWidget();
   void createMenu();

private:
    Ui::Widget *ui;

    QMenu *m_AddMenu;
    QMenu *m_PopMenu;

    //QMenu *m_AddSchoolClass;
    QAction *m_AddSchoolAction;
    QAction *m_AddClassAction;
    QAction *m_DelAction;
private slots:
    //信号和槽的参数要匹配QTreeWidgetItem *item, int column(QTreeWidgetItem *item, int column)
    void onSetLabelText(QTreeWidgetItem *item, int column);
    void addSchool();
    void addClass();
    void delAction();

protected:
    void contextMenuEvent(QContextMenuEvent *event);//重新函数

};

#endif // WIDGET_H
