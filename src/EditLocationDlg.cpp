/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "EditLocationDlg.h"

EditLocationDlg::EditLocationDlg() {
    setupUi(this);
    connectActions();

    this->locationTableWidget->setColumnCount(7);
    loadTableFromFile();
}

EditLocationDlg::EditLocationDlg(SolarCalc &sc) {
    setupUi(this);
    
}

void EditLocationDlg::connectActions() {
    connect(
        this->okButton, SIGNAL(clicked()),
        this, SLOT(saveTableToFile())
    );
}

void EditLocationDlg::loadTableFromFile() {
    QFile f(QString(locationsTXTDir + "locations.txt"));
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening locations.txt";
    }
    
    QString line;
    while (!f.atEnd()) {
        line = f.readLine();
        if (line == "\n") {
            break;
        }
        line = line.trimmed();
        parseLineInFile(line);
    }
    f.close();
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
    }
    locationTableWidget->setSortingEnabled(true);
    locationTableWidget->sortItems(0);
}

void EditLocationDlg::saveTableToFile() {
    int rows = locationTableWidget->rowCount();
    int cols = locationTableWidget->columnCount();
    QFile l(QString(locationsTXTDir + "locations.txt"));
    QFile temp(QString(locationsTXTDir + "temp"));
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

    if (!l.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Creating locations.txt to store data.";
    }
    if (!temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Creating temp file for writing.";
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

    l.close();
    temp.close();
    l.remove();
    temp.rename(QString(locationsTXTDir + "locations.txt"));

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
