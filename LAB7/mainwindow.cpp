#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentId(1)
{

    ui->setupUi(this);

    this->setWindowTitle("Деталі відправлення");

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addShipment);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteShipment);
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::updateShipment);
    connect(ui->showButton, &QPushButton::clicked, this, &MainWindow::showShipments);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addShipment()
{
    QString sender = ui->senderEdit->text().trimmed();
    QString receiver = ui->receiverEdit->text().trimmed();
    double weight = ui->weightEdit->text().toDouble();
    QString type = ui->typeEdit->text().trimmed();

    if (sender.isEmpty() || receiver.isEmpty() || type.isEmpty() || weight <= 0) {
        showError("Заповніть усі поля");
        return;
    }

    shipments.emplace_back(currentId++, sender, receiver, weight, type);
    showMessage("Відправлення успішно додано!");

    showShipments();
}

void MainWindow::deleteShipment()
{
    int id = ui->idEdit->text().toInt();
    auto it = find_if(shipments.begin(), shipments.end(), [id](Shipment s)
    {
        return s.getId() == id;
    });

    if (it != shipments.end()) {
        shipments.erase(it);
        showMessage("Відправлення успішно видалено!");
    } else {
        showError("Відправлення з таким ідентифікатором не знайдено!");
    }

    showShipments();
}

void MainWindow::updateShipment()
{
    int id = ui->idEdit->text().toInt();
    QString newSender = ui->senderEdit->text().trimmed();
    QString newReceiver = ui->receiverEdit->text().trimmed();
    double newWeight = ui->weightEdit->text().toDouble();
    QString newType = ui->typeEdit->text().trimmed();

    auto it = find_if(shipments.begin(), shipments.end(), [id](Shipment s)
    {
        return s.getId() == id;
    });

    if (it != shipments.end()) {
        it->setSender(newSender);
        it->setReceiver(newReceiver);
        it->setWeight(newWeight);
        it->setType(newType);
        showMessage("Відправлення успішно оновлено!");
    } else {
        showError("Відправлення з таким ідентифікатором не знайдено!");
    }

    showShipments();
}

void MainWindow::showShipments()
{
    ui->listWidget->clear();
    for (const auto &shipment : shipments) {
        ui->listWidget->addItem(
            QString("ID: %1 | Відправник: %2 | Отримувач: %3 | Вага: %4 | Тип: %5")
                .arg(shipment.getId())
                .arg(shipment.getSender())
                .arg(shipment.getReceiver())
                .arg(shipment.getWeight())
                .arg(shipment.getType())
            );
    }
}

void MainWindow::showMessage(QString message)
{
    QMessageBox::information(this, "Успіх", message);
}

void MainWindow::showError(QString message)
{
    QMessageBox::warning(this, "Помилка", message);
}
