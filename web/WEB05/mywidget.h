#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QTimer>

class QWebEngineView;


namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    Ui::myWidget *ui;
   //QWebEngineView * view;
    QTimer *mTimer;
    QString str;


private slots:
   void AddJavascriptWindowObject();
   void on_pushButton_clicked();
   void onCall(QString strText);
   void update();
};

#endif // MYWIDGET_H
