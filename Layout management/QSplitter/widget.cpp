#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //主分割窗口
    splitterMain = new QSplitter(Qt::Horizontal,0);
    textLeft= new QTextEdit(QObject::tr("Left Widget"),
                              splitterMain);
    //设置字体对齐方式
    textLeft->setAlignment(Qt::AlignCenter);

    splitterRight = new QSplitter(Qt::Vertical,splitterMain);
    textUp = new QTextEdit(QObject::tr("Top widget"),splitterRight);

    textBottom = new QTextEdit(QObject::tr("Bottom widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    //设置拉伸系数
    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("splitter"));
    splitterMain->show();
}

Widget::~Widget()
{

}
