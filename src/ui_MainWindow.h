/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *closeAction;
    QAction *saveLocationAction;
    QAction *loadLocationAction;
    QAction *editLocationAction;
    QAction *aboutAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
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
    QLabel *label_5;
    QLineEdit *tzInput;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *dstCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *dateLabel;
    QLabel *label_7;
    QLabel *timeLabel;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *customDateCheckBox;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *sunriseLabel;
    QLabel *label_2;
    QLabel *noonLabel;
    QLabel *label_3;
    QLabel *sunsetLabel;
    QSpacerItem *horizontalSpacer_4;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLabel *eqTimeLabel;
    QLabel *label_8;
    QLabel *sdLabel;
    QLabel *label_10;
    QLabel *aeLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *calcButton;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(540, 300);
        MainWindow->setMinimumSize(QSize(200, 200));
        MainWindow->setMaximumSize(QSize(1000, 1000));
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QStringLiteral("closeAction"));
        saveLocationAction = new QAction(MainWindow);
        saveLocationAction->setObjectName(QStringLiteral("saveLocationAction"));
        loadLocationAction = new QAction(MainWindow);
        loadLocationAction->setObjectName(QStringLiteral("loadLocationAction"));
        editLocationAction = new QAction(MainWindow);
        editLocationAction->setObjectName(QStringLiteral("editLocationAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 150));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        latLabel = new QLabel(groupBox);
        latLabel->setObjectName(QStringLiteral("latLabel"));

        verticalLayout->addWidget(latLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        latInput = new QLineEdit(groupBox);
        latInput->setObjectName(QStringLiteral("latInput"));
        latInput->setMinimumSize(QSize(75, 0));
        latInput->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(latInput);

        latCombo = new QComboBox(groupBox);
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

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lonLabel = new QLabel(groupBox);
        lonLabel->setObjectName(QStringLiteral("lonLabel"));

        verticalLayout_2->addWidget(lonLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lonInput = new QLineEdit(groupBox);
        lonInput->setObjectName(QStringLiteral("lonInput"));
        lonInput->setMinimumSize(QSize(75, 0));
        lonInput->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(lonInput);

        lonCombo = new QComboBox(groupBox);
        lonCombo->setObjectName(QStringLiteral("lonCombo"));
        sizePolicy.setHeightForWidth(lonCombo->sizePolicy().hasHeightForWidth());
        lonCombo->setSizePolicy(sizePolicy);
        lonCombo->setMaximumSize(QSize(45, 25));

        horizontalLayout_2->addWidget(lonCombo);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        tzInput = new QLineEdit(groupBox);
        tzInput->setObjectName(QStringLiteral("tzInput"));
        tzInput->setMinimumSize(QSize(70, 0));
        tzInput->setMaximumSize(QSize(70, 16777215));
        tzInput->setContextMenuPolicy(Qt::ActionsContextMenu);
        tzInput->setMaxLength(5);

        verticalLayout_3->addWidget(tzInput);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        dstCheckBox = new QCheckBox(groupBox);
        dstCheckBox->setObjectName(QStringLiteral("dstCheckBox"));

        horizontalLayout_4->addWidget(dstCheckBox);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        dateLabel = new QLabel(groupBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        gridLayout->addWidget(dateLabel, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        timeLabel = new QLabel(groupBox);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout->addWidget(timeLabel, 1, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer_3 = new QSpacerItem(35, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        customDateCheckBox = new QCheckBox(groupBox);
        customDateCheckBox->setObjectName(QStringLiteral("customDateCheckBox"));

        horizontalLayout_3->addWidget(customDateCheckBox);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMaximumDateTime(QDateTime(QDate(7999, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(7999, 12, 31));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit);

        timeEdit = new QTimeEdit(groupBox);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(timeEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_3);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        sunriseLabel = new QLabel(groupBox_2);
        sunriseLabel->setObjectName(QStringLiteral("sunriseLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sunriseLabel);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        noonLabel = new QLabel(groupBox_2);
        noonLabel->setObjectName(QStringLiteral("noonLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, noonLabel);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        sunsetLabel = new QLabel(groupBox_2);
        sunsetLabel->setObjectName(QStringLiteral("sunsetLabel"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sunsetLabel);


        horizontalLayout_5->addLayout(formLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        eqTimeLabel = new QLabel(groupBox_2);
        eqTimeLabel->setObjectName(QStringLiteral("eqTimeLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, eqTimeLabel);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        sdLabel = new QLabel(groupBox_2);
        sdLabel->setObjectName(QStringLiteral("sdLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sdLabel);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        aeLabel = new QLabel(groupBox_2);
        aeLabel->setObjectName(QStringLiteral("aeLabel"));
        aeLabel->setMouseTracking(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, aeLabel);


        horizontalLayout_5->addLayout(formLayout);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 2, 1);

        verticalSpacer = new QSpacerItem(20, 75, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(24, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        calcButton = new QPushButton(centralwidget);
        calcButton->setObjectName(QStringLiteral("calcButton"));

        gridLayout_3->addWidget(calcButton, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(loadLocationAction);
        menu_File->addAction(saveLocationAction);
        menu_File->addSeparator();
        menu_File->addAction(closeAction);
        menu_Edit->addAction(editLocationAction);
        menu_Help->addAction(aboutAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Solar Calculator", Q_NULLPTR));
        closeAction->setText(QApplication::translate("MainWindow", "&Close", Q_NULLPTR));
        saveLocationAction->setText(QApplication::translate("MainWindow", "&Save Location", Q_NULLPTR));
        loadLocationAction->setText(QApplication::translate("MainWindow", "&Load Location", Q_NULLPTR));
        editLocationAction->setText(QApplication::translate("MainWindow", "&Locations", Q_NULLPTR));
        aboutAction->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Inputs", Q_NULLPTR));
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
        tzInput->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>UTC offset of the location. For example, Florida, US' UTC offset is -5. China's UTC offset is 8. For 15 minute offsets, such as in Nepal (UTC +5:45), enter 5.75.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tzInput->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        dstCheckBox->setToolTip(QApplication::translate("MainWindow", "Is Daylight Savings Time in affect at location?", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        dstCheckBox->setText(QApplication::translate("MainWindow", "DST?", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Date:", Q_NULLPTR));
        dateLabel->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Time:", Q_NULLPTR));
        timeLabel->setText(QString());
        customDateCheckBox->setText(QApplication::translate("MainWindow", "Custom Date:", Q_NULLPTR));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MMM/yyyy", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Outputs", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Sunrise:", Q_NULLPTR));
        sunriseLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Noon:", Q_NULLPTR));
        noonLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Sunset:", Q_NULLPTR));
        sunsetLabel->setText(QApplication::translate("MainWindow", "--:--", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Equation of Time (minutes):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        eqTimeLabel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>An astronomical term accounting for changes in the time of solar noon for a given location over the course of a year.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        eqTimeLabel->setText(QApplication::translate("MainWindow", "0.000", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Solar Declination (degrees):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sdLabel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The solar declination varies from -23.44\302\260 at the (northern hemisphere) winter solstice, through 0\302\260 at the vernal equinox, to +23.44\302\260 at the summer solstice.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        sdLabel->setText(QApplication::translate("MainWindow", "0.000", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Azimuth | Elevation (degrees):", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        aeLabel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>An angular coordinate system for locating positions in the sky. Azimuth is measured clockwise from true north to the point on the horizon directly below the object. Elevation is measured vertically from that point on the horizon up to the object.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        aeLabel->setText(QApplication::translate("MainWindow", "0.000 | 0.000", Q_NULLPTR));
        calcButton->setText(QApplication::translate("MainWindow", "Calculate", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
