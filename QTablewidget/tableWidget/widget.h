#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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
    void on_insertBtn_clicked();

    void on_delBtn_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
