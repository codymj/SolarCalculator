/********************************************************************************
** Form generated from reading UI file 'EditLocationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLOCATIONDLG_H
#define UI_EDITLOCATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditLocationDlg
{
public:
    QTableView *locationTableView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *EditLocationDlg)
    {
        if (EditLocationDlg->objectName().isEmpty())
            EditLocationDlg->setObjectName(QStringLiteral("EditLocationDlg"));
        EditLocationDlg->resize(542, 241);
        locationTableView = new QTableView(EditLocationDlg);
        locationTableView->setObjectName(QStringLiteral("locationTableView"));
        locationTableView->setGeometry(QRect(10, 10, 521, 192));
        locationTableView->setAlternatingRowColors(true);
        locationTableView->setSortingEnabled(true);
        widget = new QWidget(EditLocationDlg);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 210, 521, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(EditLocationDlg);

        QMetaObject::connectSlotsByName(EditLocationDlg);
    } // setupUi

    void retranslateUi(QDialog *EditLocationDlg)
    {
        EditLocationDlg->setWindowTitle(QApplication::translate("EditLocationDlg", "Dialog", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("EditLocationDlg", "&Add", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("EditLocationDlg", "&Delete", Q_NULLPTR));
        pushButton->setText(QApplication::translate("EditLocationDlg", "&Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditLocationDlg: public Ui_EditLocationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONDLG_H
