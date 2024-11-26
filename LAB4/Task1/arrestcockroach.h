#ifndef ARRESTCOCKROACH_H
#define ARRESTCOCKROACH_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QVector>

class ArrestCockroach : public QMainWindow {
    Q_OBJECT

public:
    ArrestCockroach(QWidget *parent = nullptr);
    ~ArrestCockroach();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void moveCockroach();
    void checkIfCaught();

    QPoint cockroachPosition;
    QVector<QPoint> drawnPoints;
    bool drawing;
    QTimer *timer;
};

#endif // ARRESTCOCKROACH_H
