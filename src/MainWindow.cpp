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

SolarCalc MainWindow::storeDataIntoObj() {
    double lat = latInput->text().toDouble();
    double lon = lonInput->text().toDouble();
    this->timeZone = tzInput->text().toDouble();
    int ns = latCombo->currentIndex();
    int ew = lonCombo->currentIndex();
    this->location = Location(lat, ns, lon, ew);
    if (customDateTime) {
        this->date = dateEdit->date();
        this->time = this->timeEdit->time();
    }
    else {
        this->date = QDate::currentDate();
        this->time = QTime::currentTime();
    }

    return SolarCalc(date, time, location, timeZone, dst);
}

// Slot to run calculation when button is clicked
void MainWindow::runCalculation() {
    this->currentLocation = storeDataIntoObj();
    this->currentLocation.calculate();
    
    // Set results
    this->eqTimeLabel->setText(this->currentLocation.getEquationOfTime());
    this->sdLabel->setText(this->currentLocation.getSolarDeclination());
    this->aeLabel->setText(this->currentLocation.getAzimuthElevation());
    this->sunriseLabel->setText(this->currentLocation.getSunrise());
    this->noonLabel->setText(this->currentLocation.getNoon());
    this->sunsetLabel->setText(this->currentLocation.getSunset());
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
    connect(
        this->saveLocationAction, SIGNAL(triggered()),
        this, SLOT(saveLocation())
    );
    connect(
        this->editLocationAction, SIGNAL(triggered()),
        this, SLOT(editLocations())
    );
    connect(
        this->aboutAction, SIGNAL(triggered()),
        this, SLOT(showAboutDlg())
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
	this->dateLabel->setEnabled(false);
	this->timeLabel->setEnabled(false);
    }
    else {
        this->customDateTime = 0;
        this->dateEdit->setEnabled(false);
        this->timeEdit->setEnabled(false);
        changeDate(QDate::currentDate());
        changeTime(QTime::currentTime());
	this->dateLabel->setEnabled(true);
	this->timeLabel->setEnabled(true);
    }
}

//
void MainWindow::editLocations() {
    // Get location from table
    EditLocationDlg *editDlg = new EditLocationDlg(2);
    editDlg->exec();
    delete editDlg;
}

// Slot to load locations from file
void MainWindow::loadLocation() {
    // Save current input data in case load is cancelled
    SolarCalc inputBackup = storeDataIntoObj();

    // Get location from table
    EditLocationDlg *editDlg = new EditLocationDlg(1);
    if (editDlg->exec()) {
        this->currentLocation = editDlg->loadLocation();
    }
    else {
        this->currentLocation = inputBackup;
        delete editDlg;
        return;
    }
    delete editDlg;

    // Enter location data
    this->setWindowTitle("Solar Calculator - " + this->currentLocation.getId());
    this->latInput->setText(QString::number(this->currentLocation.getLocation().getLat()));
    this->lonInput->setText(QString::number(this->currentLocation.getLocation().getLon()));
    if (this->latInput->text().toDouble() >= 0) {
        this->latCombo->setCurrentIndex(0);
    }
    else {
        this->latCombo->setCurrentIndex(1);
    }
    if (this->lonInput->text().toDouble() >= 0) {
        this->lonCombo->setCurrentIndex(0);
    }
    else {
        this->lonCombo->setCurrentIndex(1);
    }
    this->dateEdit->setDate(this->currentLocation.getDate());
    this->timeEdit->setTime(this->currentLocation.getTime());
    this->tzInput->setText(QString::number(this->currentLocation.getTimeZone()));
    if (this->tzInput->text().toDouble() > 14.0) {
        this->tzInput->setText("14");
    }
    else if (this->tzInput->text().toDouble() < -12.0) {
        this->tzInput->setText("-12");
    }
    this->dstCheckBox->setChecked(this->currentLocation.getDST());
}

// Slot to save locations to file
void MainWindow::saveLocation() {
    storeDataIntoObj();

    QString id;
    IdDlg *idDlg = new IdDlg();
    if (idDlg->exec()) {
        id = idDlg->idInput->text();
    }
    delete idDlg;

    QString dataToSave;
    dataToSave = id;
    dataToSave += "$";
    dataToSave += QString::number(this->currentLocation.getLocation().getLat());
    dataToSave += " ";
    dataToSave += QString::number(this->currentLocation.getLocation().getLon());
    dataToSave += " ";
    dataToSave += currentLocation.getDate().toString("yyyy/MM/dd");
    dataToSave += " ";
    dataToSave += currentLocation.getTime().toString("HH:mm");
    dataToSave += " ";
    dataToSave += QString::number(currentLocation.getTimeZone());
    dataToSave += " ";
    dataToSave += currentLocation.getDST() ? "1" : "0";
    qDebug() << dataToSave;

    QFile locationsTxt("config/locations.txt");
    if (!locationsTxt.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening locations.txt.";
        return;
    }

    QFile temp("config/temp");
    if (!temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error creating temp file.";
        return;
    }
    QTextStream write(&temp);

    QString line = "";
    while (!line.isNull()) {
        line = locationsTxt.readLine();
        if (line == "\n") {
            break;
        }
        write << line;
    }
    write << dataToSave;

    locationsTxt.close();
    temp.close();
    locationsTxt.remove();
    temp.rename("config/locations.txt");
}

//
void MainWindow::showAboutDlg() {
    AboutDlg *aboutDlg = new AboutDlg();
    aboutDlg->exec();
    delete aboutDlg;
}
