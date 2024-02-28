#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButtonConvert, &QPushButton::clicked, this, &MainWindow::convertCurrency);

    ui -> fromCurrencyComboBox -> addItem("USD");
    ui -> fromCurrencyComboBox -> addItem("EUR");
    ui -> fromCurrencyComboBox -> addItem("AMD");

    ui -> toCurrencyComboBox -> addItem("USD");
    ui -> toCurrencyComboBox -> addItem("EUR");
    ui -> toCurrencyComboBox -> addItem("AMD");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::convertCurrency() {
    QString fromCurrency = ui -> fromCurrencyComboBox -> currentText();
    QString toCurrency = ui -> toCurrencyComboBox -> currentText();
    double amount = ui-> lineEditAmount -> text().toDouble();

    double usdToEurRate = 0.923773;
    double usdToAmdRate = 404.32;
    double eurToAmdRate = 437.68;

    double convertedValue;

    if (fromCurrency == "USD" && toCurrency == "EUR") {
        convertedValue = amount * usdToEurRate;
    } else if (fromCurrency == "USD" && toCurrency == "AMD") {
        convertedValue = amount * usdToAmdRate;
    } else if (fromCurrency == "EUR" && toCurrency == "USD") {
        convertedValue = amount / usdToEurRate;
    } else if (fromCurrency == "EUR" && toCurrency == "AMD") {
        convertedValue = amount * eurToAmdRate;
    } else if (fromCurrency == "AMD" && toCurrency == "USD") {
        convertedValue = amount / usdToAmdRate;
    } else if (fromCurrency == "AMD" && toCurrency == "EUR") {
        convertedValue = amount / eurToAmdRate;
    } else {
        convertedValue = amount;
    }

    QString result = QString::number(amount) + " " + fromCurrency + " = " + QString::number(convertedValue) + " " + toCurrency;
    ui -> labelResult -> setText(result);

}

