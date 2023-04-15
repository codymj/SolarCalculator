/********************************************************************************
** Form generated from reading UI file 'AboutDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutDlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *iconLabel;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *AboutDlg)
    {
        if (AboutDlg->objectName().isEmpty())
            AboutDlg->setObjectName("AboutDlg");
        AboutDlg->resize(490, 270);
        AboutDlg->setMinimumSize(QSize(490, 270));
        AboutDlg->setMaximumSize(QSize(490, 270));
        gridLayout = new QGridLayout(AboutDlg);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        iconLabel = new QLabel(AboutDlg);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setMinimumSize(QSize(64, 64));
        iconLabel->setMaximumSize(QSize(64, 64));

        horizontalLayout_3->addWidget(iconLabel);

        label = new QLabel(AboutDlg);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        textBrowser = new QTextBrowser(AboutDlg);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(405, 150));
        textBrowser->setMaximumSize(QSize(405, 150));
        textBrowser->setAcceptDrops(false);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setAcceptRichText(true);

        horizontalLayout_2->addWidget(textBrowser);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(AboutDlg);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(AboutDlg);
        QObject::connect(pushButton, &QPushButton::clicked, AboutDlg, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(AboutDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutDlg)
    {
        AboutDlg->setWindowTitle(QCoreApplication::translate("AboutDlg", "Dialog", nullptr));
        iconLabel->setText(QString());
        label->setText(QCoreApplication::translate("AboutDlg", "Solar Calculator", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Droid Sans Fallback';\">Author: Cody Johnson &lt;</span><a href=\"mailto:codyj@protonmail.com\"><span style=\" font-family:'Droid Sans Fallback'; text-decoration: underline; color:#0000ff;\">codyj@protonmail.com</span></a><span style=\" font-family:'Droid Sans Fallback';\">&gt;<br />Github: </span><a href=\"https://github.com/codymj/SolarCalculator\"><span style=\" font-family:'Droid Sans Fallback'; text-decoration: underline; color:#0000ff;\">https://github.com/codymj/SolarCalculator</span></a></p>\n"
"<p style=\"-qt-paragraph-typ"
                        "e:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Droid Sans Fallback';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Droid Sans Fallback';\">Credit to NOAA Solar Calculator for their back-end code:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://www.esrl.noaa.gov/gmd/grad/solcalc/\"><span style=\" font-family:'Droid Sans Fallback'; text-decoration: underline; color:#0000ff;\">https://www.esrl.noaa.gov/gmd/grad/solcalc/</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Droid Sans Fallback';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Droid Sans Fallback';\">With help from Wikipedia:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://en.wikipedia.org/wiki/Sunrise_equation\"><span style=\" font-family:'Droid Sans Fallback'; text-decoration: underline; color:#0000ff;\">https://en.wikipedia.org/wiki/Sunrise_equation</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Droid Sans Fallback';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Droid Sans Fallback';\">And of course Qt:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://www.qt.io/"
                        "\"><span style=\" font-family:'Droid Sans Fallback'; text-decoration: underline; color:#0000ff;\">https://www.qt.io/</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Droid Sans Fallback';\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("AboutDlg", "&Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDlg: public Ui_AboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLG_H
