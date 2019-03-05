/********************************************************************************
** Form generated from reading UI file 'webwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBWIDGET_H
#define UI_WEBWIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebWidget
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;

    void setupUi(QWidget *WebWidget)
    {
        if (WebWidget->objectName().isEmpty())
            WebWidget->setObjectName(QStringLiteral("WebWidget"));
        WebWidget->resize(557, 410);
        gridLayout = new QGridLayout(WebWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        webView = new QWebView(WebWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 1);


        retranslateUi(WebWidget);

        QMetaObject::connectSlotsByName(WebWidget);
    } // setupUi

    void retranslateUi(QWidget *WebWidget)
    {
        WebWidget->setWindowTitle(QApplication::translate("WebWidget", "WebWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class WebWidget: public Ui_WebWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBWIDGET_H
