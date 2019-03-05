#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool m_move;
    QPoint m_startPoint;
    QPoint m_windowPoint;
    QNetworkAccessManager *manage;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void RefreshTime();//刷新时间
    void RefreshWeather();//刷新天气
    void replyFinished(QNetworkReply *reply);
    void WeatherDataAnalyze(QByteArray &WeaDat);
};

#endif // MAINWINDOW_H
