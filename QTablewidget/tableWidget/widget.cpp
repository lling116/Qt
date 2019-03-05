#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置输入框大小
    ui->lineEdit->setMaximumWidth(200);
    //提示文本
    ui->lineEdit->setPlaceholderText("search");
    //设置默认行数
    ui->tableWidget->setRowCount(5);
    //设置默认列数
    ui->tableWidget->setColumnCount(15);
    //隔行变色
     ui->tableWidget->setAlternatingRowColors(true);
    //默认选中一行
     ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
     //平均分布列宽,
     ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_insertBtn_clicked()
{
    //添加行，获取当前行+1
   int currRow =  ui->tableWidget->currentRow();
   ui->tableWidget->insertRow(currRow+1);
}


void Widget::on_delBtn_clicked()
{
    int currRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currRow);
}

//搜索框，把不符合的选项的隐藏起来

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        int  rowCount = ui->tableWidget->rowCount();
        for(int row= 0; row < rowCount; row++)
        {   //显示行的序列号
            ui->tableWidget->showRow(row);
        }

        return;
    }

     int  rowCount = ui->tableWidget->rowCount();
     int  columnCount = ui->tableWidget->columnCount();

     for(int row = 0; row < rowCount;row++)
     {
         QString rowData;

         for(int column = 0; column < columnCount; column++ )
         {
             if(ui->tableWidget->item(row,column))
             {
                 //因为是按行显示：把这一行的数据连在一块
                 rowData += ui->tableWidget->item(row,column)->text();
             }
         }

         if(!rowData.isEmpty())
         {
             if(rowData.contains(arg1))
             {
                 ui->tableWidget->showRow(row);
             }
             else
             {
                 ui->tableWidget->hideRow(row);
             }
         }

         else{
             ui->tableWidget->hideRow(row);
         }
     }
}
