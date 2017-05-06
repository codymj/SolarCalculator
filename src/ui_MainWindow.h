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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
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
    QPushButton *calcButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
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
    QLabel *label_5;
    QLineEdit *tzInput;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *dstCheckBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *dateLabel;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *sunriseLabel;
    QLabel *label_2;
    QLabel *noonLabel;
    QLabel *label_3;
    QLabel *sunsetLabel;
    QWidget *widget3;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLabel *eqTimeLabel;
    QLabel *label_8;
    QLabel *sdLabel;
    QLabel *label_10;
    QLabel *aeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(570, 200);
        MainWindow->setMinimumSize(QSize(570, 200));
        MainWindow->setMaximumSize(QSize(570, 200));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        calcButton = new QPushButton(centralwidget);
        calcButton->setObjectName(QStringLiteral("calcButton"));
        calcButton->setGeometry(QRect(480, 170, 80, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 449, 53));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        latLabel = new QLabel(widget);
        latLabel->setObjectName(QStringLiteral("latLabel"));

        verticalLayout->addWidget(latLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        latInput = new QLineEdit(widget);
        latInput->setObjectName(QStringLiteral("latInput"));
        latInput->setMinimumSize(QSize(75, 0));
        latInput->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(latInput);

        latCombo = new QComboBox(widget);
        latCombo->setObjectName(QStringLiteral("latCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(latCombo->sizePolicy().hasHeightForWidth());
        latCombo->setSizePolicy(sizePolicy);
        latCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout->addWidget(latCombo);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lonLabel = new QLabel(widget);
        lonLabel->setObjectName(QStringLiteral("lonLabel"));

        verticalLayout_2->addWidget(lonLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lonInput = new QLineEdit(widget);
        lonInput->setObjectName(QStringLiteral("lonInput"));
        lonInput->setMinimumSize(QSize(75, 0));
        lonInput->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(lonInput);

        lonCombo = new QComboBox(widget);
        lonCombo->setObjectName(QStringLiteral("lonCombo"));
        sizePolicy.setHeightForWidth(lonCombo->sizePolicy().hasHeightForWidth());
        lonCombo->setSizePolicy(sizePolicy);
        lonCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout_2->addWidget(lonCombo);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        tzInput = new QLineEdit(widget);
        tzInput->setObjectName(QStringLiteral("tzInput"));
        tzInput->setMinimumSize(QSize(70, 0));
        tzInput->setMaximumSize(QSize(70, 16777215));
        tzInput->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout_3->addWidget(tzInput);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        dstCheckBox = new QCheckBox(widget);
        dstCheckBox->setObjectName(QStringLiteral("dstCheckBox"));

        verticalLayout_4->addWidget(dstCheckBox);


        horizontalLayout_3->addLayout(verticalLayout_4);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(21, 80, 138, 22));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        dateLabel = new QLabel(widget1);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        horizontalLayout_4->addWidget(dateLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(22, 126, 151, 63));
        formLayout_2 = new QFormLayout(widget2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        sunriseLabel = new QLabel(widget2);
        sunriseLabel->setObjectName(QStringLiteral("sunriseLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sunriseLabel);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        noonLabel = new QLabel(widget2);
        noonLabel->setObjectName(QStringLiteral("noonLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, noonLabel);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        sunsetLabel = new QLabel(widget2);
        sunsetLabel->setObjectName(QStringLiteral("sunsetLabel"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sunsetLabel);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(180, 126, 291, 63));
        formLayout = new QFormLayout(widget3);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        eqTimeLabel = new QLabel(widget3);
        eqTimeLabel->setObjectName(QStringLiteral("eqTimeLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, eqTimeLabel);

        label_8 = new QLabel(widget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        sdLabel = new QLabel(widget3);
        sdLabel->setObjectName(QStringLiteral("sdLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sdLabel);

        label_10 = new QLabel(widget3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        aeLabel = new QLabel(widget3);
        aeLabel->setObjectName(QStringLiteral("aeLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, aeLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        calcButton->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        latLabel->setText(QApplication::translate("MainWindow", "Latitude:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        latInput->setToolTip(QApplication::translate("MainWindow", "Latitude of location as decimal.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        latInput->setText(QApplication::translate("MainWindow", "0.000000", Q_NULLPTR));
        latCombo->clear();
        latCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "N", Q_NULLPTR)
         << QApplication::translate("MainWindow", "S", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        latCombo->setToolTip(QApplication::translate("MainWindow", "Is the latitude north or south of the equator?", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lonLabel->setText(QApplication::translate("MainWindow", "Longitude:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lonInput->setToolTip(QApplication::translate("MainWindow", "Longitude of location as decimal.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lonInput->setText(QApplication::translate("MainWindow", "0.000000", Q_NULLPTR));
        lonCombo->clear();
        lonCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "E", Q_NULLPTR)
         << QApplication::translate("MainWindow", "W", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        lonCombo->setToolTip(QApplication::translate("MainWindow", "Is the longitude east or west of the Prime Meridian?", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("MainWindow", "Time Zone:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tzInput->setToolTip(QApplication::translate("MainWindow", "<html>\n"
"<head/>\n"
"<body>\n"
"<p>UTC offset of the location.<br /><br />For example, Florida, US' UTC offset is -5. <br />China's UTC offset is 8. For 15 minute offsets, such as in Nepal (UTC +5:45), <br />enter 5.75.</p>\n"
"</body>\n"
"</html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        dstCheckBox->setToolTip(QApplication::translate("MainWindow", "Is Daylight Savings Time in affect at location?", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        dstCheckBox->setText(QApplication::translate("MainWindow", "DST?", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Date:", Q_NULLPTR));
        dateLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Sunrise:", Q_NULLPTR));
        sunriseLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Noon:", Q_NULLPTR));
        noonLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Sunset:", Q_NULLPTR));
        sunsetLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Equation of Time (minutes):", Q_NULLPTR));
        eqTimeLabel->setText(QApplication::translate("MainWindow", "0.000", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Solar Declination (degrees):", Q_NULLPTR));
        sdLabel->setText(QApplication::translate("MainWindow", "0.000", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Azimuth | Elevation (degrees):", Q_NULLPTR));
        aeLabel->setText(QApplication::translate("MainWindow", "0.000 | 0.000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
