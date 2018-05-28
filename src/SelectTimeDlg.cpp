// =============================================================================
//
// SelectTimeDlg.cpp
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#include "SelectTimeDlg.h"

SelectTimeDlg::SelectTimeDlg() {
    setupUi(this);

    connectActions();

    this->time = QTime::currentTime();
    this->hourSpinBox->setValue(this->time.hour());
    this->minuteSpinBox->setValue(this->time.minute());
}

void SelectTimeDlg::connectActions() {
    connect(
        this->hourSpinBox, SIGNAL(valueChanged(int)),
        this, SLOT(setTimeHour(int))
    );
    connect(
        this->minuteSpinBox, SIGNAL(valueChanged(int)),
        this, SLOT(setTimeMinute(int))
    );
}

void SelectTimeDlg::setTimeHour(int h) {
    int m = this->time.minute();
    QTime updatedTime(h, m);
    this->time = updatedTime;
    this->timeStr = this->time.toString("HH:mm");
}

void SelectTimeDlg::setTimeMinute(int m) {
    int h = this->time.hour();
    QTime updatedTime(h, m);
    this->time = updatedTime;
    this->timeStr = this->time.toString("HH:mm");
}

QString SelectTimeDlg::getTimeStr() {
    return this->timeStr;
}
