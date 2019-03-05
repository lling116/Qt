#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QMessageBox>
#include<QHostInfo>
#include<QNetworkInterface>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void getHostInformation();

private:
    Ui::Widget *ui;
    QLabel*  hostLabel;
    QLineEdit *lineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;
public slots:
    void  slotDetail();
};

#endif // WIDGET_H
