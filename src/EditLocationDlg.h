/*
 * EditLocationDlg.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _EDITLOCATIONDLG_H_
#define _EDITLOCATIONDLG_H_

#include <QCalendarWidget>
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QString>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QTime>
#include "Location.h"
#include "MainWindow.h"
#include "SolarCalc.h"
#include "SelectDateDlg.h"
#include "SelectTimeDlg.h"
#include "ui_EditLocationDlg.h"

class EditLocationDlg : public QDialog, public Ui::EditLocationDlg {
    Q_OBJECT

public:
    EditLocationDlg(int);

    SolarCalc loadLocation();

private:
    int mode;
    QList<QTableWidgetItem *> tableItemList;
    void loadTableFromFile();
    void parseLineInFile(QString &);

    void connectActions();

    SolarCalc locationToLoad;

private slots:
    void saveTableToFile();
    void addRowToTable();
    void deleteRowFromTable();
    void validateInput(QTableWidgetItem *);
    void setDateTimeInTable(QTableWidgetItem *);
    void createLocationToLoad();
};

#endif // _EDITLOCATIONDLG_H_
