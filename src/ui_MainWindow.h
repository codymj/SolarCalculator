/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *latLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *latInput;
    QComboBox *latCombo;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *lonLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lonInput;
    QComboBox *lonCombo;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *elevLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *elevInput;
    QComboBox *elevCombo;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *sunriseLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *noonLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *sunsetLabel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *closeButton;
    QPushButton *calcButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 180);
        MainWindow->setMinimumSize(QSize(640, 180));
        MainWindow->setMaximumSize(QSize(640, 180));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 597, 53));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        latLabel = new QLabel(layoutWidget);
        latLabel->setObjectName(QStringLiteral("latLabel"));

        verticalLayout->addWidget(latLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        latInput = new QLineEdit(layoutWidget);
        latInput->setObjectName(QStringLiteral("latInput"));

        horizontalLayout->addWidget(latInput);

        latCombo = new QComboBox(layoutWidget);
        latCombo->setObjectName(QStringLiteral("latCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(latCombo->sizePolicy().hasHeightForWidth());
        latCombo->setSizePolicy(sizePolicy);
        latCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout->addWidget(latCombo);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lonLabel = new QLabel(layoutWidget);
        lonLabel->setObjectName(QStringLiteral("lonLabel"));

        verticalLayout_2->addWidget(lonLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lonInput = new QLineEdit(layoutWidget);
        lonInput->setObjectName(QStringLiteral("lonInput"));

        horizontalLayout_2->addWidget(lonInput);

        lonCombo = new QComboBox(layoutWidget);
        lonCombo->setObjectName(QStringLiteral("lonCombo"));
        sizePolicy.setHeightForWidth(lonCombo->sizePolicy().hasHeightForWidth());
        lonCombo->setSizePolicy(sizePolicy);
        lonCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout_2->addWidget(lonCombo);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        elevLabel = new QLabel(layoutWidget);
        elevLabel->setObjectName(QStringLiteral("elevLabel"));

        verticalLayout_3->addWidget(elevLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        elevInput = new QLineEdit(layoutWidget);
        elevInput->setObjectName(QStringLiteral("elevInput"));

        horizontalLayout_3->addWidget(elevInput);

        elevCombo = new QComboBox(layoutWidget);
        elevCombo->setObjectName(QStringLiteral("elevCombo"));
        sizePolicy.setHeightForWidth(elevCombo->sizePolicy().hasHeightForWidth());
        elevCombo->setSizePolicy(sizePolicy);
        elevCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout_3->addWidget(elevCombo);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 80, 131, 78));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        sunriseLabel = new QLabel(widget);
        sunriseLabel->setObjectName(QStringLiteral("sunriseLabel"));

        horizontalLayout_5->addWidget(sunriseLabel);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        noonLabel = new QLabel(widget);
        noonLabel->setObjectName(QStringLiteral("noonLabel"));

        horizontalLayout_6->addWidget(noonLabel);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        sunsetLabel = new QLabel(widget);
        sunsetLabel->setObjectName(QStringLiteral("sunsetLabel"));

        horizontalLayout_7->addWidget(sunsetLabel);


        verticalLayout_4->addLayout(horizontalLayout_7);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(460, 140, 167, 26));
        horizontalLayout_8 = new QHBoxLayout(widget1);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        closeButton = new QPushButton(widget1);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_8->addWidget(closeButton);

        calcButton = new QPushButton(widget1);
        calcButton->setObjectName(QStringLiteral("calcButton"));

        horizontalLayout_8->addWidget(calcButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        latLabel->setText(QApplication::translate("MainWindow", "Latitude:", Q_NULLPTR));
        latCombo->clear();
        latCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "N", Q_NULLPTR)
         << QApplication::translate("MainWindow", "S", Q_NULLPTR)
        );
        lonLabel->setText(QApplication::translate("MainWindow", "Longitude:", Q_NULLPTR));
        lonCombo->clear();
        lonCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "E", Q_NULLPTR)
         << QApplication::translate("MainWindow", "W", Q_NULLPTR)
        );
        elevLabel->setText(QApplication::translate("MainWindow", "Elevation:", Q_NULLPTR));
        elevCombo->clear();
        elevCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "m", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ft", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "Sunrise:", Q_NULLPTR));
        sunriseLabel->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Noon:", Q_NULLPTR));
        noonLabel->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Sunset:", Q_NULLPTR));
        sunsetLabel->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
        closeButton->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        calcButton->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
