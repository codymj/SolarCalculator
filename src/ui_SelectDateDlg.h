/********************************************************************************
** Form generated from reading UI file 'SelectDateDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDATEDLG_H
#define UI_SELECTDATEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SelectDateDlg
{
public:
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *SelectDateDlg)
    {
        if (SelectDateDlg->objectName().isEmpty())
            SelectDateDlg->setObjectName(QStringLiteral("SelectDateDlg"));
        SelectDateDlg->setWindowModality(Qt::ApplicationModal);
        SelectDateDlg->resize(400, 300);
        gridLayout = new QGridLayout(SelectDateDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        calendarWidget = new QCalendarWidget(SelectDateDlg);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(SelectDateDlg);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(SelectDateDlg);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(SelectDateDlg);
        QObject::connect(okButton, SIGNAL(clicked()), SelectDateDlg, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SelectDateDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectDateDlg);
    } // setupUi

    void retranslateUi(QDialog *SelectDateDlg)
    {
        SelectDateDlg->setWindowTitle(QApplication::translate("SelectDateDlg", "Enter Date", nullptr));
        cancelButton->setText(QApplication::translate("SelectDateDlg", "&Cancel", nullptr));
        okButton->setText(QApplication::translate("SelectDateDlg", "&Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDateDlg: public Ui_SelectDateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDATEDLG_H
