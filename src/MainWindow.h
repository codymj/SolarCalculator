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
#include "Location.h"
#include "SolarCalc.h"

class MainWindow : public QMainWindow, public Ui::MainWindow {
    Q_OBJECT

public:
    // Constructors
    MainWindow();
    
public slots:

private:
    QDate date;
    Location location;
    double timeZone;
    bool dst;
    int customDate = 0;
    QDate minCustomDate = QDate(1800,1,1);
    QDate maxCustomDate = QDate(2099,12,31);
    
    void connectActions();

private slots:
    void runCalculation();
    void updateDST(const int &);
    void toggleCustomDate(const int &);
    void changeDate(const QDate &);
};

#endif // _MAINWINDOW_H_
