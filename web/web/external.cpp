#include "external.h"

External::External(QObject *parent) :
    QObject(parent)
{
}

int External::VerifyUserAccount(const QString &userName, const QString &userPwd)
{
    if((userName=="ling")&&(userPwd=="123"))
    {
        return 1;
    }

    return 0;
}

QString External::GetPropMsg()
{
    return "hello";
}
