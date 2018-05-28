/********************************************************************************
** Form generated from reading UI file 'IdDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDDLG_H
#define UI_IDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IdDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *idInput;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *IdDlg)
    {
        if (IdDlg->objectName().isEmpty())
            IdDlg->setObjectName(QStringLiteral("IdDlg"));
        IdDlg->setWindowModality(Qt::WindowModal);
        IdDlg->resize(225, 96);
        gridLayout = new QGridLayout(IdDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(IdDlg);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        idInput = new QLineEdit(IdDlg);
        idInput->setObjectName(QStringLiteral("idInput"));

        verticalLayout->addWidget(idInput);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(IdDlg);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(IdDlg);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(IdDlg);
        QObject::connect(pushButton, SIGNAL(clicked()), IdDlg, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), IdDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(IdDlg);
    } // setupUi

    void retranslateUi(QDialog *IdDlg)
    {
        IdDlg->setWindowTitle(QApplication::translate("IdDlg", "Enter ID", nullptr));
        label->setText(QApplication::translate("IdDlg", "Enter a name for this location:", nullptr));
        pushButton_2->setText(QApplication::translate("IdDlg", "&Cancel", nullptr));
        pushButton->setText(QApplication::translate("IdDlg", "&Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IdDlg: public Ui_IdDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDDLG_H
