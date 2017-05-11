/********************************************************************************
** Form generated from reading UI file 'SelectTimeDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTTIMEDLG_H
#define UI_SELECTTIMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SelectTimeDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *hourSpinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpinBox *minuteSpinBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *SelectTimeDlg)
    {
        if (SelectTimeDlg->objectName().isEmpty())
            SelectTimeDlg->setObjectName(QStringLiteral("SelectTimeDlg"));
        SelectTimeDlg->resize(221, 96);
        gridLayout = new QGridLayout(SelectTimeDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(SelectTimeDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        hourSpinBox = new QSpinBox(SelectTimeDlg);
        hourSpinBox->setObjectName(QStringLiteral("hourSpinBox"));
        hourSpinBox->setMaximum(23);

        horizontalLayout_2->addWidget(hourSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(SelectTimeDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        minuteSpinBox = new QSpinBox(SelectTimeDlg);
        minuteSpinBox->setObjectName(QStringLiteral("minuteSpinBox"));
        minuteSpinBox->setMaximum(59);

        horizontalLayout_2->addWidget(minuteSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(SelectTimeDlg);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(SelectTimeDlg);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(SelectTimeDlg);
        QObject::connect(okButton, SIGNAL(clicked()), SelectTimeDlg, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SelectTimeDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectTimeDlg);
    } // setupUi

    void retranslateUi(QDialog *SelectTimeDlg)
    {
        SelectTimeDlg->setWindowTitle(QApplication::translate("SelectTimeDlg", "Enter Time", Q_NULLPTR));
        label->setText(QApplication::translate("SelectTimeDlg", "Hours", Q_NULLPTR));
        label_2->setText(QApplication::translate("SelectTimeDlg", "Minutes", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SelectTimeDlg", "&Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("SelectTimeDlg", "&Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectTimeDlg: public Ui_SelectTimeDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTTIMEDLG_H
