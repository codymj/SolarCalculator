/*
 * MainWindow.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "MainWindow.h"

// Constructor
MainWindow::MainWindow() {
    setupUi(this);
    
    // Setup custom date/time
    toggleCustomDateTime(customDateTime);
    this->dateEdit->setMinimumDate(minCustomDate);
    this->dateEdit->setMaximumDate(maxCustomDate);
    this->dateEdit->setDate(QDate::currentDate());
    this->timeEdit->setTime(QTime::currentTime());
    
    // Create lat and lon regex & validators
    QRegExp latRegExp(
    "(\\+)?(?:90(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-8][0-9])(?:(?:\\.[0-9]{1,6})?))");
    QRegExp lonRegExp("(\\+)?(?:180(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-9][0-9]|1[0-7][0-9])(?:(?:\\.[0-9]{1,6})?))");
    QValidator *latValidator = new QRegExpValidator(latRegExp, this);
    QValidator *lonValidator = new QRegExpValidator(lonRegExp, this);
    this->latInput->setValidator(latValidator);
    this->lonInput->setValidator(lonValidator);
    
    this->dateLabel->setText(QDate::currentDate().toString(QString("dd/MMM/yyyy")));
    this->timeLabel->setText(QTime::currentTime().toString(QString("HH:mm")));
    
    // Connect signals and slots
    connectActions();
}

// Slot to run calculation when button is clicked
void MainWindow::runCalculation() {
    // Set location data
    double lat = latInput->text().toDouble();
    double lon = lonInput->text().toDouble();
    this->timeZone = tzInput->text().toDouble();
    int ns = latCombo->currentIndex();
    int ew = lonCombo->currentIndex();
    this->location = Location(lat, ns, lon, ew);
    
    if (customDateTime) {
        this->date = dateEdit->date();
    }
    else {
        this->date = QDate::currentDate();
    }
    
    // Run calculation
    SolarCalc sCalc(date, time, location, timeZone, dst);
    sCalc.calculate();
    
    // Set results
    this->eqTimeLabel->setText(sCalc.getEquationOfTime());
    this->sdLabel->setText(sCalc.getSolarDeclination());
    this->aeLabel->setText(sCalc.getAzimuthElevation());
    this->sunriseLabel->setText(sCalc.getSunrise());
    this->noonLabel->setText(sCalc.getNoon());
    this->sunsetLabel->setText(sCalc.getSunset());
}

// Connects signals/slots and file menu actions
void MainWindow::connectActions() {
    connect(
        this->calcButton, SIGNAL(clicked()),
        this, SLOT(runCalculation())
    );
    connect(
        this->dstCheckBox, SIGNAL(stateChanged(int)),
        this, SLOT(updateDST(int))
    );
    connect(
        this->customDateCheckBox, SIGNAL(stateChanged(int)),
        this, SLOT(toggleCustomDateTime(int))
    );
    connect(
        this->dateEdit, SIGNAL(dateChanged(QDate)),
        this, SLOT(changeDate(QDate))
    );
    connect(
        this->timeEdit, SIGNAL(timeChanged(QTime)),
        this, SLOT(changeTime(QTime))
    );
    connect(
        this->closeAction, SIGNAL(triggered()),
        this, SLOT(close())
    );
    connect(
        this->loadLocationAction, SIGNAL(triggered()),
        this, SLOT(loadLocation())
    );
}

// Slot to update DST value
void MainWindow::updateDST(const int &state) {
    if (state) {
        this->dst = true;
    }
    else {
        this->dst = false;
    }
}

void MainWindow::changeDate(const QDate &d) {
    this->date = d;
    dateLabel->setText(this->date.toString(QString("dd/MMM/yyyy")));
}

void MainWindow::changeTime(const QTime &t) {
    this->time = t;
    timeLabel->setText(this->time.toString(QString("HH:mm")));
}

// Slot to enable or disable custom date
void MainWindow::toggleCustomDateTime(const int &state) {
    if (state) {
        this->customDateTime = 1;
        this->dateEdit->setEnabled(true);
        this->timeEdit->setEnabled(true);
        changeDate(dateEdit->date());
        changeTime(timeEdit->time());
    }
    else {
        this->customDateTime = 0;
        this->dateEdit->setEnabled(false);
        this->timeEdit->setEnabled(false);
        changeDate(QDate::currentDate());
        changeTime(QTime::currentTime());
    }
}

// Slot to load locations from file
void MainWindow::loadLocation() {
    EditLocationDlg *dlg = new EditLocationDlg();
    if (dlg->exec()) {
        
    }
    delete dlg;
}

// Slot to save locations to file
void MainWindow::saveLocation(SolarCalc &sc) {
    
}
