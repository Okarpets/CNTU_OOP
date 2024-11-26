#include "catchflygame.h"
#include <QMessageBox>
#include <QRandomGenerator>

CatchFlyGame::CatchFlyGame(QWidget *parent)
    : QMainWindow(parent), level(1) {
    setFixedSize(800, 600);
    setWindowTitle("Fly Game");

    trap = new QLabel(this);
    trap->setPixmap(QPixmap(":/photo/trap.png").scaled(100, 100, Qt::KeepAspectRatio));
    trap->setGeometry(350, 350, 100, 100);

    window = new QLabel(this);
    window->setPixmap(QPixmap(":/photo/window.png").scaled(150, 150, Qt::KeepAspectRatio));
    window->setGeometry(600, 100, 150, 150);
    window->hide();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CatchFlyGame::moveFly);

    startLevel(1);
}

void CatchFlyGame::startLevel(int level) {
    this->level = level;

    delete fly;
    if (level == 1) {
        fly = new Level1Fly(this);
    } else if (level == 2) {
        fly = new Level2Fly(this);
        window->show();
    }

    fly->setGeometry(100, 100, 50, 50);
    fly->show();
    timer->start(100);
}

void CatchFlyGame::mousePressEvent(QMouseEvent *event) {
    if (fly->geometry().contains(event->pos())) {
        int newX = QRandomGenerator::global()->bounded(0, width() - fly->width());
        int newY = QRandomGenerator::global()->bounded(0, height() - fly->height());
        fly->move(newX, newY);
    }
    QMainWindow::mousePressEvent(event);
}

void CatchFlyGame::moveFly() {
    if (level == 2 && fly->geometry().intersects(window->geometry())) {
        dynamic_cast<Level2Fly*>(fly)->moveToWindow(window->geometry());
    } else {
        fly->moveRandomly();
    }

    if (fly->isInTrap(trap->geometry())) {
        timer->stop();
        QMessageBox::information(this, "Game Over", "You caught the fly!");
        if (level < 2) {
            startLevel(level + 1);
        } else {
            QMessageBox::information(this, "Congratulations!", "You've completed all levels!");
        }
    }
}
