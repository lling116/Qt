/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *delBtn;
    QPushButton *onBtn;
    QPushButton *cancelBtn;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QTableView *tableView;

    void setupUi(QWidget *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QStringLiteral("info"));
        info->resize(397, 330);
        gridLayout = new QGridLayout(info);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(info);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        delBtn = new QPushButton(info);
        delBtn->setObjectName(QStringLiteral("delBtn"));

        gridLayout->addWidget(delBtn, 1, 1, 1, 1);

        onBtn = new QPushButton(info);
        onBtn->setObjectName(QStringLiteral("onBtn"));

        gridLayout->addWidget(onBtn, 1, 2, 1, 1);

        cancelBtn = new QPushButton(info);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        gridLayout->addWidget(cancelBtn, 1, 3, 1, 1);

        label = new QLabel(info);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lineEdit = new QLineEdit(info);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 2);

        pushButton_2 = new QPushButton(info);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        tableView = new QTableView(info);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 4);


        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QWidget *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Form", 0));
        pushButton->setText(QApplication::translate("info", "\345\242\236\345\212\240", 0));
        delBtn->setText(QApplication::translate("info", "\345\210\240\351\231\244", 0));
        onBtn->setText(QApplication::translate("info", "\347\241\256\345\256\232", 0));
        cancelBtn->setText(QApplication::translate("info", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("info", "\350\257\267\350\276\223\345\205\245\346\237\245\346\211\276\347\232\204SN", 0));
        pushButton_2->setText(QApplication::translate("info", "\346\237\245\346\211\276", 0));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
