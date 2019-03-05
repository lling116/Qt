#ifndef MUTEX_H
#define MUTEX_H

#include <QThread>

class Mutex : public QThread
{
    Q_OBJECT
public:
    explicit Mutex(QObject *parent = nullptr);
    void run();

signals:

public slots:
private:
    int count;
};

#endif // MUTEX_H
