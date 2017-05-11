/*
 * SelectTimeDlg.h
 *
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _SELECTTIMELG_H_
#define _SELECTTIMEDLG_H_

#include <QString>
#include <QTime>
#include "ui_SelectTimeDlg.h"

class SelectTimeDlg : public QDialog, public Ui::SelectTimeDlg {
    Q_OBJECT

public:
    SelectTimeDlg();

    QString getTimeStr();
private:
    QTime time;
    QString timeStr;

    void connectActions();

private slots:
    void setTimeHour(int);
    void setTimeMinute(int);
};

#endif  // _SELECTTIMELG_H_
