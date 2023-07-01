#include "mainwindow.h"

/*******************************************************************************
* CONSTRUCTOR MAINWINDOW
*_______________________________________________________________________________
* This constructor constructs a MainWindow object.
*_______________________________________________________________________________
* PRE-CONDITIONS
* QWidget *parent
*
* POST-CONDITIONS
* None
*******************************************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/*******************************************************************************
* DESTRUCTOR MAINWINDOW
*_______________________________________________________________________________
* This destructor deconstructs a MainWindow object.
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

MainWindow::~MainWindow()
{
    delete ui;
}

/*******************************************************************************
* FUNCTION CONVERTFTOC
*_______________________________________________________________________________
* This function converts from f to c.
*_______________________________________________________________________________
* PRE-CONDITIONS
* double F
*
* POST-CONDITIONS
* double
*******************************************************************************/

double convertFtoC(double F)
{
    return ((5.0 / 9.0) * (F - 32.0));
}

/*******************************************************************************
* FUNCTION CONVERTCTOF
*_______________________________________________________________________________
* This function converts from c to f.
*_______________________________________________________________________________
* PRE-CONDITIONS
* double C
*
* POST-CONDITIONS
* double
*******************************************************************************/

double convertCtoF(double C)
{
    return ((9.0 / 5.0) * C) + 32.0;
}

/*******************************************************************************
* FUNCTION CHECKINPUT
*_______________________________________________________________________________
* This function makes sure the input is a number and not a letter or empty
*_______________________________________________________________________________
* PRE-CONDITIONS
* QString input
*
* POST-CONDITIONS
* bool
*******************************************************************************/

bool checkInput(QString input)
{
    // Prevents alpha & empty input
    string temp = input.toStdString();
    // Traverses string input
    for (unsigned i = 0; i < temp.length(); i++)
    {
        // Checks to see if digit, decimal, or neg.
        if (isdigit(temp[i]) == false && temp[i] != '.' && temp[0] != '-')
        {
            return false;
        }
    }
    return true;
}

/*******************************************************************************
* SLOT ON_CONVERTBUTTON_CLICKED
*_______________________________________________________________________________
* This function runs when the convert button is clicked
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void MainWindow::on_convertButton_clicked()
{
    // clear label
    ui->introLabel->clear();
    // run if input is valid
    if (!ui->tempInputBox->text().toStdString().empty() && checkInput(ui->tempInputBox->text()))
    {
        // run if c to f button is pressed
        if (ui->ctof->isChecked())
        {
            // set label
            ui->introLabel->setText("Converted from Celsius to Fahrenheit");
            // text to converted double
            double value = convertCtoF(ui->tempInputBox->text().toDouble());
            // output conversion
            ui->tempOutputBox->setText(QString::number(value));
            // store input as slider value and set correct range
            ui->convertSlider->setRange(value-100, value+100);
            ui->convertSlider->setValue(value);
        }
        else if (ui->ftoc->isChecked())
        {
            // set label
            ui->introLabel->setText("Converted from Fahrenheit to Celsius");
            // text to converted double
            double value = convertFtoC(ui->tempInputBox->text().toDouble());
            // output conversion
            ui->tempOutputBox->setText(QString::number(value));
            //store input as slider value and correct range
            ui->convertSlider->setRange(value-100, value+100);
            ui->convertSlider->setValue(value);
        }
        else
        {
            // output if no conversion selected
            ui->introLabel->setText("Select conversion");
        }
    }
    else
    {
        // output if incorrect input
        if(ui->tempInputBox->text().toStdString().empty())
        {
            ui->introLabel->setText("Enter a number");
        }
        else
        {
            ui->introLabel->setText("Input must be a number\nEnter a number");
        }
    }
}

/*******************************************************************************
* SLOT ON_FTOC_CLICKED
*_______________________________________________________________________________
* This function runs when the f to c radio button is clicked
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void MainWindow::on_ftoc_clicked()
{
    // set correct units
    ui->inputLabel->setText("Fahrenheit");
    ui->outputLabel->setText("Celcius");
}

/*******************************************************************************
* SLOT ON_CTOF_CLICKED
*_______________________________________________________________________________
* This function runs when the c to f radio button is clicked
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void MainWindow::on_ctof_clicked()
{
    // set correct units
    ui->inputLabel->setText("Celcius");
    ui->outputLabel->setText("Fahrenheit");
}

/*******************************************************************************
* SLOT ON_CONVERTSLIDER_VALUECHANGED
*_______________________________________________________________________________
* This function runs when the slider is moved from it inital position.
*_______________________________________________________________________________
* PRE-CONDITIONS
* int value
*
* POST-CONDITIONS
* None
*******************************************************************************/

void MainWindow::on_convertSlider_valueChanged(int value)
{
    // run if correct input for first button
    if (ui->ctof->isChecked() && !ui->tempInputBox->text().toStdString().empty() && checkInput(ui->tempInputBox->text()))
    {
        // set output to slider value
        ui->tempInputBox->setText(QString::number(convertFtoC(double(value))));
        ui->tempOutputBox->setText(QString::number(value));
    }
    // run if correct input for second button
    else if (ui->ftoc->isChecked() && !ui->tempInputBox->text().toStdString().empty() && checkInput(ui->tempInputBox->text()))
    {
        // set output to slider value
        ui->tempInputBox->setText(QString::number(convertCtoF(double(value))));
        ui->tempOutputBox->setText(QString::number(value));
    }
}

/*******************************************************************************
* SLOT ON_RESETBUTTON_CLICKED
*_______________________________________________________________________________
* This function sets the gui back to the defualt
*_______________________________________________________________________________
* PRE-CONDITIONS
* None
*
* POST-CONDITIONS
* None
*******************************************************************************/

void MainWindow::on_resetButton_clicked()
{
    // set back to default
    ui->ftoc->click();
    ui->tempInputBox->clear();
    ui->tempOutputBox->clear();
    ui->inputLabel->setText("Fahrenheit");
    ui->outputLabel->setText("Celsius");
    ui->introLabel->setText("Welcome to D&D's Lab18 converter!\nThis program converts temperature from\n fahrenheit to celsius and vice versa!\n");
    ui->convertSlider->setRange(0,99);
    ui->convertSlider->setValue(49);
}
