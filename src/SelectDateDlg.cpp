/*
 * SelectDateDlg.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/


#include "SelectDateDlg.h"

SelectDateDlg::SelectDateDlg() {
    setupUi(this);

    connectActions();

    this->date = QDate::currentDate();
}

void SelectDateDlg::connectActions() {
    connect(
        this->calendarWidget, SIGNAL(clicked(const QDate &)),
        this, SLOT(setDate(const QDate&))
    );
}

void SelectDateDlg::setDate(const QDate &d) {
    this->date = d;
    this->dateStr = this->date.toString("yyyy/MM/dd");
}

QString SelectDateDlg::getDateStr() {
    return this->dateStr;
}
