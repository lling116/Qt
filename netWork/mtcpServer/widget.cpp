#include "widget.h"


Widget::Widget(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("TcpServer"));
    ContentListWidget = new QListWidget;
    PortLabel = new QLabel(tr("端口："));
    PortLineEdit = new QLineEdit;
    CreateBtn = new QPushButton(tr("创建聊天室："));

    //网格布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(PortLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);

}

Widget::~Widget()
{

}
