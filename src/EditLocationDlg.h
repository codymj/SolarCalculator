/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _EDITLOCATIONDLG_H_
#define _EDITLOCATIONDLG_H_

#include <QDate>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QString>
#include <QTableWidgetItem>
#include <QTime>
#include "SolarCalc.h"
#include "ui_EditLocationDlg.h"

class EditLocationDlg : public QDialog, public Ui::EditLocationDlg {
    Q_OBJECT

public:
    EditLocationDlg();
    EditLocationDlg(SolarCalc &);

private:
    QList<QTableWidgetItem *> tableItemList;
    void loadTableFromFile();
    void saveTableToFile();
    SolarCalc loadLocationFromTable();
    void parseLineInFile(QString &);
};

#endif // _EDITLOCATIONDLG_H_
