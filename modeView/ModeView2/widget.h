#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QStandardItemModel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_clearBtn_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel* itemModel;
};

#endif // WIDGET_H
