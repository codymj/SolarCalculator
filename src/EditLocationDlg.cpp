/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#include "EditLocationDlg.h"

EditLocationDlg::EditLocationDlg() {
    setupUi(this);
    
    this->locationTableWidget->setColumnCount(7);
}

EditLocationDlg::EditLocationDlg(SolarCalc &sc) {
    setupUi(this);
    
}

void EditLocationDlg::loadTableFromFile() {
    QFile f("locations.txt");
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening locations.txt";
    }
    
    QString line;
    while (!f.atEnd()) {
        line = f.readLine();
        line = line.trimmed();
        parseLineInFile(line);
    }
    f.close();
}

void EditLocationDlg::parseLineInFile(QString &l) {
    double lat, lon, tz = 0.0;
    QString id, date, time = "";
    int dst = 0;
    
    QStringList idAndData = l.split('$');
    id = idAndData.at(0);
    
    QString data = idAndData.at(1);
    QStringList dataSplit = data.split(' ');
    
    lat = dataSplit.at(0).toDouble();
    lon = dataSplit.at(1).toDouble();
    date = dataSplit.at(2);
    time = dataSplit.at(3);
    tz = dataSplit.at(4).toDouble();
    dst = dataSplit.at(5).toInt();
    
    QTableWidgetItem *item = new QTableWidgetItem;
}
