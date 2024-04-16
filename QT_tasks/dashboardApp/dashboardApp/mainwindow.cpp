#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::fetchData);
    updateTimer->start(10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetchData() {
    double newData = fetchDataFromApi();
    ui->lcdNumber->display(newData);
}

double MainWindow::fetchDataFromApi() {
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://api.stockmarket.com/real-time-data"));

    QNetworkReply* reply = manager.get(request);

    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObject = document.object();

        double newData = jsonObject["stock_price"].toDouble();

        reply->deleteLater();

        return newData;
    } else {
        qDebug() << "Error fetching data:" << reply->errorString();

        reply->deleteLater();

        return 0.0;
    }
}

double MainWindow::fetchStockPrice() {
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://api.stockmarket.com/real-time-price"));

    QNetworkReply* reply = manager.get(request);

    // Block until the request is finished
    while (!reply->isFinished()) {
        qApp->processEvents();
    }

    if (reply->error() == QNetworkReply::NoError) {
        // Parse the JSON response
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObject = document.object();

        // Extract the stock price from the JSON
        double stockPrice = jsonObject["price"].toDouble();

        // Clean up
        reply->deleteLater();

        return stockPrice;
    } else {
        qDebug() << "Error fetching stock price:" << reply->errorString();

        // Clean up
        reply->deleteLater();

        // Return a default value or handle the error accordingly
        return 0.0;
    }
}
