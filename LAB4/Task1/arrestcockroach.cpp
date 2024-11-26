#include "arrestcockroach.h"

ArrestCockroach::ArrestCockroach(QWidget *parent)
    : QMainWindow(parent), drawing(false) {
    setFixedSize(800, 600);
    cockroachPosition = QPoint(QRandomGenerator::global()->bounded(width() - 30), QRandomGenerator::global()->bounded(height() - 30));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ArrestCockroach::moveCockroach);
    timer->start(1000);
}

ArrestCockroach::~ArrestCockroach() {}

void ArrestCockroach::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setBrush(Qt::black);
    painter.drawRect(cockroachPosition.x(), cockroachPosition.y(), 30, 30);

    painter.setPen(Qt::red);
    if (drawnPoints.size() > 1) {
        painter.drawPolyline(drawnPoints.data(), drawnPoints.size());
    }

    if (drawnPoints.size() > 2) {
        painter.drawLine(drawnPoints.last(), drawnPoints.first());
    }
}

void ArrestCockroach::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawnPoints.clear();
        drawnPoints.append(event->pos());
        drawing = true;
    }
}

void ArrestCockroach::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        drawnPoints.append(event->pos());
        update();
    }
}

void ArrestCockroach::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = false;
        checkIfCaught();
        update();
    }
}

void ArrestCockroach::moveCockroach() {
    cockroachPosition = QPoint(QRandomGenerator::global()->bounded(width() - 30), QRandomGenerator::global()->bounded(height() - 30));
    update();
}

void ArrestCockroach::checkIfCaught() {
    QPoint cockroachCenter(cockroachPosition.x() + 15, cockroachPosition.y() + 15);

    if (drawnPoints.size() > 2) {
        QPolygon polygon;
        for (const QPoint &point : drawnPoints) {
            polygon << point;
        }

        if (polygon.containsPoint(cockroachCenter, Qt::OddEvenFill)) {
            QMessageBox::information(this, "WIN", "You cought cockroach!");
            drawnPoints.clear();
        }
    }
}
