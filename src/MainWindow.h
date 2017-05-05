/*
 * MainWindow.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QDate>
#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>
#include <QString>
#include "ui_MainWindow.h"
#include "Elevation.h"
#include "Location.h"
#include "SolarCalc.h"

class MainWindow : public QMainWindow, public Ui::MainWindow {
    Q_OBJECT

public:
    // Constructors
    MainWindow();
    
public slots:

private:
    Location location;
    double timeZone;
    bool dst;
    QDate currentDate;
    
    void connectActions();

private slots:
    void runCalculation();
    void updateDST(const int &);
};

#endif // _MAINWINDOW_H_
