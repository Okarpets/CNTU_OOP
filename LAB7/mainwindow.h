#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "shipment.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showMessage(QString message);
    void showError(QString message);

private slots:
    void addShipment();
    void deleteShipment();
    void updateShipment();
    void showShipments();

private:
    Ui::MainWindow *ui;
    vector<Shipment> shipments;
    int currentId = 1;
};

#endif // MAINWINDOW_H
