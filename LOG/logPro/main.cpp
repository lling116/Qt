#include "widget.h"
#include <QApplication>
#include<QMutex>
#include<QFile>
#include<QDateTime>
#include<QTextStream>

void outputMessage(QtMsgType type,const QMessageLogContext &context,const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch (type) {
    case QtDebugMsg:
           text = QString("Debug");
        break;
    case QtWarningMsg:
           text = QString("Warning:");
        break;

     case QtCriticalMsg:
          text = QString("Critical:");
      break;

      case QtFatalMsg:
          text = QString("Fatal:");
        break;

    default:
        break;
    }

    QString context_info = QString("File:(%1) Line:\
                                   (%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file("../log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Widget w;
    //w.show();

    //注册MessageHandler,重定向IO口
        qInstallMessageHandler(outputMessage);

       // 要恢复消息处理程序，请调用
      //  qInstallMessageHandler(0);

        //打印日志到文件中
        qDebug("This is a debug message");
        qWarning("This is a warning message");
        qCritical("This is a critical message");
       //qFatal("This is a fatal message");

    return a.exec();
}
