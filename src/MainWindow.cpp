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
    QRegExp elevRegExp("[0-9]\\d{0,4}");
    
    QValidator *latValidator = new QRegExpValidator(latRegExp, this);
    QValidator *lonValidator = new QRegExpValidator(lonRegExp, this);
    QValidator *elevValidator = new QRegExpValidator(elevRegExp, this);
    
    latInput->setValidator(latValidator);
    lonInput->setValidator(lonValidator);
    elevInput->setValidator(elevValidator);
    
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
        this->elevInput, SIGNAL(textChanged(QString)),
        this, SLOT(checkElevation(QString))
    );
    connect(
        this->elevCombo, SIGNAL(currentIndexChanged(int)),
        this, SLOT(emitElevComboChanged(int))
    );
}

// Slot to run calculation when button is clicked
void MainWindow::runCalculation() {
    // Set location data
    double lat = latInput->text().toDouble();
    double lon = lonInput->text().toDouble();
    int ns = latCombo->currentIndex();
    int ew = lonCombo->currentIndex();
    this->location = Location(lat, ns, lon, ew);
    
    // Set elevation data
    double elev = elevInput->text().toDouble();
    int elevUnit = elevCombo->currentIndex();
    this->elevation = Elevation(elev, elevUnit);
    
    // Run calculation
    SolarCalc sCalc(location, elevation);
    sCalc.calculate();
    
    // Set results
    this->sunriseLabel->setText(sCalc.getSunrise());
    this->noonLabel->setText(sCalc.getHighNoon());
    this->sunsetLabel->setText(sCalc.getSunset());
}

// Slot to check elevation. Accepted values are 0-30000 (ft) and 0-9144 (m)
void MainWindow::checkElevation(QString e) {
    int elevation = 0;
    
    if (e.isEmpty()) {
        this->calcButton->setDisabled(true);
        return;
    }
    else {
        elevation = e.toInt();
    }
    
    // Check elevation in m
    if (this->elevCombo->currentIndex() == 0) {
        if (elevation < 0 || elevation > 9144) {
            this->calcButton->setDisabled(true);
            return;
        }
        else {
            this->calcButton->setDisabled(false);
            return;
        }
    }
    // Check elevation in ft
    if (this->elevCombo->currentIndex() == 1) {
        if (elevation < 0 || elevation > 30000) {
            this->calcButton->setDisabled(true);
            return;
        }
        else {
            this->calcButton->setDisabled(false);
            return;
        }
    }
}

// Updates validator for elevation input if unit is changed from combo box
void MainWindow::emitElevComboChanged(int i) {
    if (i >= 0) {
        emit this->elevInput->textChanged(this->elevInput->text());
    }
}
