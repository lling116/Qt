#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "win_qextserialport.h"
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int ConvertHexChar(char ch);
    void StrTurn(QString str);
    unsigned int GetCrcCode(unsigned char *pData,unsigned char wLen);

private slots:
    void on_pushButton_clicked();
    void readMyCom();

private:
    Ui::Widget *ui;
    Win_QextSerialPort* myCom;
    QTimer *readTimer;
    int Value[200];
    QString p;
    int *crcArray;
};

#endif // WIDGET_H
