/*
 * SelectDateDlg.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SELECTDATEDLG_H_
#define _SELECTDATEDLG_H_

#include <QDate>
#include <QString>
#include "ui_SelectDateDlg.h"

class SelectDateDlg : public QDialog, public Ui::SelectDateDlg {
    Q_OBJECT

public:
    SelectDateDlg();

    QString getDateStr();
private:
    QDate date;
    QString dateStr;

    void connectActions();

private slots:
    void setDate(const QDate &);
};

#endif  // _SELECTDATEDLG_H_
