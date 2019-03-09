#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSplitter>
#include<QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QSplitter *splitterMain;
    QSplitter *splitterRight;

    QTextEdit *textLeft;
    QTextEdit *textUp;
    QTextEdit *textBottom;

};

#endif // WIDGET_H
