/*
 * MainWindow.h
 * 
 * Author:  Cody Johnson <codyj@protonmail.com>
*/

#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

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
    Elevation elevation;
    Location location;
    
    void connectActions();

private slots:
    void checkElevation(QString);
    void emitElevComboChanged(int);
    void runCalculation();
};

#endif // _MAINWINDOW_H_
