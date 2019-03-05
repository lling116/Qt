#ifndef RUNTHREAD_H
#define RUNTHREAD_H

#include <QThread>
#include <QWidget>

class runThread : public QThread
{
    Q_OBJECT
public:
    explicit runThread(QObject *parent = nullptr);
    void run();

signals:

public slots:
};

#endif // RUNTHREAD_H
