/*
 * SelectDateDlg.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SELECTDATEDLG_H_
#define _SELECTDATEDLG_H_

#include "ui_SelectDateDlg.h"

class SelectDateDlg : public QDialog, public Ui::SelectDateDlg {
    Q_OBJECT

public:
    SelectDateDlg();

private:
    QDate date;
    QString dateStr;
};
