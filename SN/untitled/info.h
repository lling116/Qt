#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class info;
}

class info : public QWidget
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = 0);
    ~info();
    QString getLoaclTime();

public slots:
    void insertSN(QString snInf);

private slots:
    void on_pushButton_clicked();

    void on_onBtn_clicked();

    void on_cancelBtn_clicked();

    void on_delBtn_clicked();

    void on_pushButton_2_clicked();


    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::info *ui;
    QSqlTableModel *model;
};

#endif // INFO_H
