/*
 * MainWindow.cpp
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "MainWindow.h"

// Constructor
MainWindow::MainWindow() {
    setupUi(this);
    
    // Create lat and lon regex & validators
    QRegExp latRegExp(
    "(\\+)?(?:90(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-8][0-9])(?:(?:\\.[0-9]{1,6})?))");
    QRegExp lonRegExp("(\\+)?(?:180(?:(?:\\.0{1,6})?)|(?:[0-9]|[1-9][0-9]|1[0-7][0-9])(?:(?:\\.[0-9]{1,6})?))");
    QValidator *latValidator = new QRegExpValidator(latRegExp, this);
    QValidator *lonValidator = new QRegExpValidator(lonRegExp, this);
    latInput->setValidator(latValidator);
    lonInput->setValidator(lonValidator);
    
    dateLabel->setText(QDate::currentDate().toString(QString("dd MMM yyyy")));
    
    // Connect signals and slots
    connectActions();
}

// Connects signals and slots
void MainWindow::connectActions() {
    connect(
        this->calcButton, SIGNAL(clicked()),
        this, SLOT(runCalculation())
    );
    connect(
        this->dstCheckBox, SIGNAL(stateChanged(int)),
        this, SLOT(updateDST(int))
    );
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
    
    // Run calculation
    SolarCalc sCalc(location, timeZone, dst);
    sCalc.calculate();
    
    // Set results
    this->dateLabel->setText(sCalc.getDate());
    this->eqTimeLabel->setText(sCalc.getEquationOfTime());
    this->sdLabel->setText(sCalc.getSolarDeclination());
    this->aeLabel->setText(sCalc.getAzimuthElevation());
    this->sunriseLabel->setText(sCalc.getSunrise());
    this->noonLabel->setText(sCalc.getNoon());
    this->sunsetLabel->setText(sCalc.getSunset());
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
