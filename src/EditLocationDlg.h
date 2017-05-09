/*
 * SolarCalcs.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _EDITLOCATIONDLG_H_
#define _EDITLOCATIONDLG_H_

#include <QDate>
#include <QDebug>
#include <QList>
#include <QString>
#include <QTime>
#include "SolarCalc.h"
#include "ui_EditLocationDlg.h"

class EditLocationDlg : public QDialog, public Ui::EditLocationDlg {
    Q_OBJECT

public:
    EditLocationDlg();
    EditLocationDlg(SolarCalc &);

private:
    QList<SolarCalc> solarCalcList;
    void loadTableFromFile();
    void saveTableToFile();
    SolarCalc loadLocationFromTable();

};

#endif // _EDITLOCATIONDLG_H_
