#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDialog>
#include<QListWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QGridLayout>

class Widget : public QDialog
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~Widget();

private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;
};

#endif // WIDGET_H
