#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <QObject>

class External : public QObject
{
    Q_OBJECT
    // 声明静态属性msg
    Q_PROPERTY (QString msg READ getMsg WRITE setMsg)
public:
    explicit External(QObject *parent = 0);

signals:
    void mouseClicked();
public slots:
     //void TestPassObject(QObject*);
public:
     QString getMsg() const { return msg; }
     void setMsg( const QString& strMsg ) { msg = strMsg; }
     // 提供给Javascript方法,需要用Q_INVOKABLE修饰
     Q_INVOKABLE int VerifyUserAccount(const QString& userName, const QString& userPwd);
     Q_INVOKABLE QString GetPropMsg();
 //  Q_INVOKABLE void TestPassObjectToNative(QObject*);
     QString msg;

};

#endif // EXTERNAL_H
