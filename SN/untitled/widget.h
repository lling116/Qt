#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "win_qextserialport.h"
#include <QTimer>
#include "info.h"

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
    void on_pushButton_2_clicked();

signals:
    void snStrSignal(QString sn);

private:
    Ui::Widget *ui;
    Win_QextSerialPort* myCom;
    QTimer *readTimer;
    int Value[200];
    QString p;
    int *crcArray;
    info *inf;
    QString snStr;
    bool isOpen;
};

#endif // WIDGET_H
