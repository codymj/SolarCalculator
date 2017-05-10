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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditLocationDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *locationTableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *EditLocationDlg)
    {
        if (EditLocationDlg->objectName().isEmpty())
            EditLocationDlg->setObjectName(QStringLiteral("EditLocationDlg"));
        EditLocationDlg->resize(722, 329);
        gridLayout = new QGridLayout(EditLocationDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        locationTableWidget = new QTableWidget(EditLocationDlg);
        if (locationTableWidget->columnCount() < 7)
            locationTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        locationTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        locationTableWidget->setObjectName(QStringLiteral("locationTableWidget"));
        locationTableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        locationTableWidget->setAlternatingRowColors(true);
        locationTableWidget->setSortingEnabled(true);
        locationTableWidget->setColumnCount(7);
        locationTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        locationTableWidget->horizontalHeader()->setDefaultSectionSize(100);
        locationTableWidget->horizontalHeader()->setHighlightSections(true);
        locationTableWidget->horizontalHeader()->setMinimumSectionSize(5);
        locationTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        locationTableWidget->horizontalHeader()->setStretchLastSection(false);
        locationTableWidget->verticalHeader()->setVisible(true);
        locationTableWidget->verticalHeader()->setCascadingSectionResizes(false);
        locationTableWidget->verticalHeader()->setHighlightSections(true);
        locationTableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(locationTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(EditLocationDlg);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(EditLocationDlg);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(EditLocationDlg);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(EditLocationDlg);

        QMetaObject::connectSlotsByName(EditLocationDlg);
    } // setupUi

    void retranslateUi(QDialog *EditLocationDlg)
    {
        EditLocationDlg->setWindowTitle(QApplication::translate("EditLocationDlg", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = locationTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EditLocationDlg", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = locationTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EditLocationDlg", "Latitude", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = locationTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EditLocationDlg", "Longitude", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = locationTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("EditLocationDlg", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = locationTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("EditLocationDlg", "Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = locationTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("EditLocationDlg", "Time Zone", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = locationTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("EditLocationDlg", "DST", Q_NULLPTR));
        addButton->setText(QApplication::translate("EditLocationDlg", "&Add", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("EditLocationDlg", "&Delete", Q_NULLPTR));
        okButton->setText(QApplication::translate("EditLocationDlg", "&Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditLocationDlg: public Ui_EditLocationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONDLG_H
