#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QInputDialog>
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->schLabel->setMinimumWidth(150);
    ui->classLabel->setMidLineWidth(150);

    //设置表头
    ui->treeWidget->setHeaderLabel("school/class");
    initTreeWidget();
    createMenu();
   // m_PopMenu->exec();

    //qt treeWidget的信号
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem* , int)),this,SLOT(onSetLabelText(QTreeWidgetItem *, int)));

}

Widget::~Widget()
{
    delete ui;
}

//初始化树形空间
void Widget::initTreeWidget()
{

    {
        QTreeWidgetItem *JinNiuSchool = new QTreeWidgetItem(ui->treeWidget);
        JinNiuSchool->setText(0,"Jin Niu School");

        QTreeWidgetItem *JinNiuClassOne = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClassOne->setText(0,"Jin Niu Class one");

        QTreeWidgetItem *JinNiuClassTwo = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClassTwo->setText(0,"Jin Niu Class Two");

        QTreeWidgetItem *JinNiuClassThree = new QTreeWidgetItem(JinNiuSchool);
        JinNiuClassThree->setText(0,"Jin Niu Class Three");

    }

    {
        QTreeWidgetItem *QingYangSchool = new QTreeWidgetItem(ui->treeWidget);
        QingYangSchool->setText(0,"Qing Yang School");

        QTreeWidgetItem *QingYangClassOne = new QTreeWidgetItem(QingYangSchool);
        QingYangClassOne->setText(0,"Qing Yang Class One");

        QTreeWidgetItem *QingYangClassTwo = new QTreeWidgetItem(QingYangSchool);
        QingYangClassTwo->setText(0,"Qing Yang Class Two");

        QTreeWidgetItem *QingYangClassThree = new QTreeWidgetItem(QingYangSchool);
        QingYangClassThree->setText(0,"Qing Yang Class Three");

    }

}

/*
 * 1.menu可以添加动作或者子菜单
 * 2.
 */

void Widget::createMenu()
{
    //弹出菜单
    m_PopMenu = new QMenu;
    m_PopMenu->setIcon(QIcon("../icons/add.png"));

    m_AddMenu = new QMenu("Add Action");
   //初始化动作的文字
    m_AddSchoolAction = new QAction(this);
    m_AddSchoolAction->setText("Add School");

    m_AddClassAction =  new QAction(this);
    m_AddClassAction->setText("Add Class");
    m_AddMenu->setIcon(QIcon("../icons/add.png"));


    m_DelAction = new QAction(this);
    m_DelAction->setText("Del Action");
    m_DelAction->setIcon(QIcon("../icons/del.jpg"));

    //向菜单添加动作
    m_AddMenu->addAction(m_AddSchoolAction);
    m_AddMenu->addAction(m_AddClassAction);

    //添加子菜单和动作
    m_PopMenu->addMenu(m_AddMenu);
    m_PopMenu->addAction(m_DelAction);

    connect(m_AddSchoolAction,SIGNAL(triggered()),this,SLOT(addSchool()));
    connect(m_AddClassAction,SIGNAL(triggered()),this,SLOT(addClass()));
     connect(m_DelAction,SIGNAL(triggered()),this,SLOT(delAction()));
}

void Widget::onSetLabelText(QTreeWidgetItem *item, int column)
{
    qDebug()<<column;
    if(item->parent())
    {
        ui->schLabel->setText(item->parent()->text(0));
        ui->classLabel->setText(item->text(0));
    }
    else {
         ui->schLabel->setText(item->text(0));
         ui->classLabel->setText("dont choice");
    }
}

void Widget::addSchool()
{
    //添加学校，通过菜单实现
    qDebug()<<"添加学校";
    bool ok;
    QString schoolText = QInputDialog::getText(this,tr("Inout School Name"),
                                             tr("school name"),QLineEdit::Normal,"",&ok);
   if(ok &&!schoolText.isEmpty())
   {
       QTreeWidgetItem* schoolItem = new QTreeWidgetItem(ui->treeWidget);
       schoolItem->setText(0,schoolText);
   }


}

void Widget::addClass()
{
    //添加班级
    qDebug()<<"添加班级";
    //获取当前所在的item
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    bool ok;
    QString classText = QInputDialog::getText(this,tr("Inout class Name"),
                                             tr("class name"),QLineEdit::Normal,"",&ok);
  if(!currentItem)
  {
     QMessageBox::information(this,"information","pleace a School");
  }
    if(currentItem->parent())
    {
        if(ok &&!classText.isEmpty())
       {
           QTreeWidgetItem* classItem = new QTreeWidgetItem(currentItem->parent());
           classItem->setText(0,classText);
       }
    }
    else{
        QTreeWidgetItem* classItem = new QTreeWidgetItem(currentItem);
        classItem->setText(0,classText);
    }

}

void Widget::delAction()
{

    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();

    if(currentItem->parent())
    {
        qDebug()<<ui->treeWidget->currentIndex();
        currentItem->parent()->removeChild(currentItem);
    }
    else{
        //indexOfTopLevelItem顶层Item
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(currentItem));
    }

}


//右键菜单事件
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    if(ui->treeWidget->hasFocus())
    {   //获得鼠标坐标，并把弹出菜单移动到此位置
        m_PopMenu->move(cursor().pos());
        m_PopMenu->show();
    }
}


