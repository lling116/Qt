#include "external.h"

External::External(QObject *parent) :
    QObject(parent)
{
}

void External::TestPassObject(QObject *)
{

}

int External::VerifyUserAccount(const QString &userName, const QString &userPwd)
{
    return  0;
}

QString External::GetPropMsg()
{
    return "11";
}

void External::TestPassObjectToNative(QObject *)
{

}
