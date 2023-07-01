/*******************************************************************************
* AUTHOR       : Dillon Welsh, David Dang
* LAB18        : QT WIDGETS
* CLASS        : CS 3A
* SECTION      : 71206
* DUE DATE     : 11/20/2020
*******************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QApplication>
#include <QLineEdit>
#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
* MAINWINDOW CLASS
*_______________________________________________________________________________
* This program defines the functions and constructors for the MainWindow Class.
*_______________________________________________________________________________
* INPUT:
*  "MainWindow.h": The function and constructor
*	declarations for the MainWindow class
*
* OUTPUT:
*  None
*******************************************************************************/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
/*******************************************************************************
* CONSTRUCTOR MAINWINDOW
*_______________________________________________________________________________
* This constructor constructs a MainWindow object.
*******************************************************************************/
    MainWindow(QWidget *parent = nullptr);
/*******************************************************************************
* DESTRUCTOR MAINWINDOW
*_______________________________________________________________________________
* This destructor deconstructs a MainWindow object.
*******************************************************************************/
    ~MainWindow();

private slots:
/*******************************************************************************
* SLOT ON_CONVERTBUTTON_CLICKED
*_______________________________________________________________________________
* This function runs when the convert button is clicked.
*******************************************************************************/
    void on_convertButton_clicked();
/*******************************************************************************
* SLOT ON_FTOC_CLICKED
*_______________________________________________________________________________
* This function runs when the f to c radio button is clicked.
*******************************************************************************/
    void on_ftoc_clicked();
/*******************************************************************************
* SLOT ON_CTOF_CLICKED
*_______________________________________________________________________________
* This function runs when the c to f radio button is clicked.
*******************************************************************************/
    void on_ctof_clicked();
/*******************************************************************************
* SLOT ON_CONVERTSLIDER_VALUECHANGED
*_______________________________________________________________________________
* This function runs when the slider is moved from it inital position.
*******************************************************************************/
    void on_convertSlider_valueChanged(int value);
/*******************************************************************************
* SLOT ON_RESETBUTTON_CLICKED
*_______________________________________________________________________________
* This function sets the gui back to the defualt.
*******************************************************************************/
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;
};

/*******************************************************************************
* FUNCTION CONVERTFTOC
*_______________________________________________________________________________
* This function converts from f to c.
*******************************************************************************/
double convertFtoC(double F);
/*******************************************************************************
* FUNCTION CONVERTCTOF
*_______________________________________________________________________________
* This function converts from c to f.
*******************************************************************************/
double convertCtoF(double C);
/*******************************************************************************
* FUNCTION CHECKINPUT
*_______________________________________________________________________________
* This function makes sure the input is a number and not a letter or empty.
*******************************************************************************/
bool checkInput(QString);

#endif // MAINWINDOW_H
