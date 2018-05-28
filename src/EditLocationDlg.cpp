// =============================================================================
//
// EditLocationDlg.cpp
// Author: Cody Johnson <codyj@protonmail.com>
//
// =============================================================================
#include "EditLocationDlg.h"

EditLocationDlg::EditLocationDlg(int mode) {
    setupUi(this);
    this->mode = mode;

    if (this->mode == 1) {    // Load location
        this->okButton->setText("&Load");
        this->addButton->setEnabled(false);
        this->deleteButton->setEnabled(false);
        connect(
            this->okButton, SIGNAL(clicked()),
            this, SLOT(createLocationToLoad())
        );
    }
    else if (this->mode == 2) {    // Edit/save data to file
        this->okButton->setText("&Save");
        connect(
            this->okButton, SIGNAL(clicked()),
            this, SLOT(saveTableToFile())
        );
    }
    connectActions();

    this->locationTableWidget->setColumnCount(7);
    loadTableFromFile();
}

void EditLocationDlg::connectActions() {
    connect(
        this->locationTableWidget, SIGNAL(itemClicked(QTableWidgetItem*)),
        this, SLOT(setDateTimeInTable(QTableWidgetItem *))
    );
    connect(
        this->addButton, SIGNAL(clicked()),
        this, SLOT(addRowToTable())
    );
    connect(
        this->deleteButton, SIGNAL(clicked()),
        this, SLOT(deleteRowFromTable())
    );
}

void EditLocationDlg::loadTableFromFile() {
    QFile locationsTxt("config/locations.txt");
    if (!locationsTxt.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening locations.txt";
        return;
    }
    
    QString line = "";
    while (!line.isNull()) {
        line = locationsTxt.readLine();
        if (line == "\n" || line == "") {
            continue;
        }
        line = line.trimmed();
        parseLineInFile(line);
    }
    locationsTxt.close();
    this->locationTableWidget->resizeColumnsToContents();
}

void EditLocationDlg::parseLineInFile(QString &l) {
    QVector<QString> params;
    QString id, lat, lon, date, time, tz, dst = "";
    
    // Split entire line into ID and data strings
    if (!l.contains('$')) {
        qDebug() << "File is corrupt.";
        return;
    }
    
    QStringList idAndData = l.split('$');
    id = idAndData.at(0);
    
    // Split data string into SolarCalc parameters
    QString data = idAndData.at(1);
    QStringList dataSplit = data.split(' ');
    if (dataSplit.count() != 6) {
        qDebug() << "File is corrupt.";
        return;
    }

    lat = dataSplit.at(0);
    lon = dataSplit.at(1);
    date = dataSplit.at(2);
    time = dataSplit.at(3);
    tz = dataSplit.at(4);
    dst = dataSplit.at(5);
    params << id << lat << lon << date << time << tz << dst;
    
    // Create an item for each column (parameters) in a new top-inserted row
    locationTableWidget->setSortingEnabled(false);
    locationTableWidget->insertRow(0);
    for (int i=0; i<locationTableWidget->columnCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(params.at(i));
        locationTableWidget->setItem(0,i,item);
        if (this->mode == 1) {  // Read-only for loading
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
    }
    locationTableWidget->setSortingEnabled(true);
    locationTableWidget->sortItems(0);
}

void EditLocationDlg::saveTableToFile() {
    int rows = locationTableWidget->rowCount();
    int cols = locationTableWidget->columnCount();

    QFile locationsTxt("config/locations.txt");
    if (!locationsTxt.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening locations.txt";
        return;
    }

    QFile temp("config/temp");
    if (!temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error creating temp file.";
        return;
    }
    QTextStream write(&temp);
    QString line;

    // Validate all inputs first
    QTableWidgetItem *item;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            item = locationTableWidget->item(i,j);
            validateInput(item);
        }
    }

    for (int i=0; i<rows; i++) {
        line.clear();
        for (int j=0; j<cols; j++) {
            line += locationTableWidget->item(i,j)->text();
            line += (j == 0 ? "$" : " ");
        }
        line += "\n";
        write << line;
    }

    locationsTxt.close();
    temp.close();
    locationsTxt.remove();
    temp.rename("config/locations.txt");

    this->close();
}

void EditLocationDlg::validateInput(QTableWidgetItem *item) {
    int col = item->column();

    // Check latitude
    if (col == 1) {
        double value = item->text().toDouble();
        if (value == 0.0) {
            item->setText("0.0");
        }
        else if (value > 90.000000) {
            item->setText("90.000000");
        }
        else if (value < -90.000000) {
            item->setText("-90.000000");
        }
    }

    // Check longitude
    else if (col == 2) {
        double value = item->text().toDouble();
        if (value == 0.0) {
            item->setText("0.0");
        }
        else if (value > 180.000000) {
            item->setText("180.000000");
        }
        else if (value < -180.000000) {
            item->setText("-180.000000");
        }
    }

    // Check time zone
    else if (col == 5) {
        double value = item->text().toDouble();
        if (value == 0.0) {
            item->setText("0");
        }
        else if (value > 14.00) {
            item->setText("14.00");
        }
        else if (value < -12.00) {
            item->setText("-12.00");
        }
    }

    // Date and time will be input by widgets
    else {
        return;
    }
}

void EditLocationDlg::setDateTimeInTable(QTableWidgetItem *item) {
    int col = item->column();

    // Set date
    if (col == 3) {
        QString dateStr;
        SelectDateDlg *dateDlg = new SelectDateDlg();
        if (dateDlg->exec()) {
            dateStr = dateDlg->getDateStr();
            item->setText(dateStr);
        }
        delete dateDlg;
    }

    // Set time
    else if (col == 4) {
        QString timeStr;
        SelectTimeDlg *timeDlg = new SelectTimeDlg();
        if (timeDlg->exec()) {
            timeStr = timeDlg->getTimeStr();
            item->setText(timeStr);
        }
        delete timeDlg;
    }
}

void EditLocationDlg::addRowToTable() {
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QTableWidgetItem *newId = new QTableWidgetItem("ID");
    QTableWidgetItem *newLat = new QTableWidgetItem("0.000000");
    QTableWidgetItem *newLon = new QTableWidgetItem("0.000000");
    QTableWidgetItem *newDate = new QTableWidgetItem(date.toString("yyyy/MM/dd"));
    QTableWidgetItem *newTime = new QTableWidgetItem(time.toString("HH:mm"));
    QTableWidgetItem *newTz = new QTableWidgetItem("0");
    QTableWidgetItem *newDst = new QTableWidgetItem("0");
    QList<QTableWidgetItem *> newItemList;
    newItemList << newId << newLat << newLon << newDate << newTime << newTz << newDst;

    locationTableWidget->setSortingEnabled(false);
    this->locationTableWidget->insertRow(0);
    int cols = locationTableWidget->columnCount();
    for (int i=0; i<cols; i++) {
        locationTableWidget->setItem(0,i,newItemList.at(i));
        qDebug() << newItemList.at(i)->text();
    }
}

void EditLocationDlg::deleteRowFromTable() {
    int row = this->locationTableWidget->currentRow();
    this->locationTableWidget->removeRow(row);
}

void EditLocationDlg::createLocationToLoad() {
    int row = this->locationTableWidget->currentRow();
    int cols = this->locationTableWidget->columnCount();
    QTableWidgetItem *item;
    QString id;
    QDate date;
    QTime time;
    Location location;
    double tz = 0.0;
    bool dst = false;

    for (int i=0; i<cols; i++) {
        item = this->locationTableWidget->item(row,i);
        if (i == 0) {   // ID
            id = item->text();
        }
        else if (i == 1) {  // Latitude
            location.setLat(item->text().toDouble());
        }
        else if (i == 2) {  // Longitude
            location.setLon(item->text().toDouble());
        }
        else if (i == 3) {  // Date
            date = QDate::fromString(item->text(), "yyyy/MM/dd");
        }
        else if (i == 4) {  // Time
            time = QTime::fromString(item->text(), "HH:mm");
        }
        else if (i == 5) {  // Time Zone
            tz = item->text().toDouble();
        }
        else if (i == 6) {  // DST
            dst = item->text().toInt();
        }
    }

    this->locationToLoad = SolarCalc(date, time, location, tz, dst);
    this->locationToLoad.setId(id);
}

SolarCalc EditLocationDlg::loadLocation() {
    return this->locationToLoad;
}
