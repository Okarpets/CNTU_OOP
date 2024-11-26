#include "catchflygame.h"
#include <QMessageBox>
#include <QRandomGenerator>

CatchFlyGame::CatchFlyGame(QWidget *parent)
    : QMainWindow(parent), level(1), score(0)
{
    setFixedSize(800, 600);
    setWindowTitle("Fly Game");

    room = new QLabel(this);
    room->setPixmap(QPixmap(":/photo/room.png").scaled(size(), Qt::KeepAspectRatioByExpanding));
    room->setGeometry(0, 0, width(), height());
    room->lower();

    trap = new QLabel(this);
    trap->setPixmap(QPixmap(":/photo/trap.png").scaled(100, 100, Qt::KeepAspectRatio));
    trap->setGeometry(350, 350, 100, 100);

    window = new QLabel(this);
    window->setPixmap(QPixmap(":/photo/window.png").scaled(150, 150, Qt::KeepAspectRatio));
    window->setGeometry(600, 100, 150, 150);
    window->hide();

    door = new QLabel(this);
    door->setPixmap(QPixmap(":/photo/door.png").scaled(150, 200, Qt::KeepAspectRatio));
    door->setGeometry(100, 400, 150, 200);
    door->hide();

    scoreLabel = new QLabel(this);
    scoreLabel->setText("Score: 0");
    scoreLabel->setGeometry(10, 10, 100, 30);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CatchFlyGame::moveFlies);

    startLevel(1);
}

void CatchFlyGame::mousePressEvent(QMouseEvent *event)
{
    for (Fly *fly : flies)
    {
        if (fly->geometry().contains(event->pos()))
        {
            score++;
            updateScore();

            int newX = QRandomGenerator::global()->bounded(0, width() - fly->width());
            int newY = QRandomGenerator::global()->bounded(0, height() - fly->height());
            fly->move(newX, newY);
        }
    }
    QMainWindow::mousePressEvent(event);
}

void CatchFlyGame::startLevel(int level)
{
    this->level = level;
    qDeleteAll(flies);
    flies.clear();
    delete frog;
    frog = nullptr;

    window->setVisible(level > 1);
    door->setVisible(level == 3);
    trap->setVisible(level < 3);

    if (level == 1)
    {
        Fly *fly = new Level1Fly(this);
        int x = QRandomGenerator::global()->bounded(width() - 50);
        int y = QRandomGenerator::global()->bounded(height() - 50);
        fly->setGeometry(x, y, 50, 50);
        flies.append(fly);
        fly->show();
    }
    else if (level == 2)
    {
        Fly *fly1 = new Level1Fly(this);
        int x1 = QRandomGenerator::global()->bounded(width() - 50);
        int y1 = QRandomGenerator::global()->bounded(height() - 50);
        fly1->setGeometry(x1, y1, 50, 50);
        flies.append(fly1);
        fly1->show();

        Fly *fly2 = new Level2Fly(this);
        int x2 = QRandomGenerator::global()->bounded(width() - 50);
        int y2 = QRandomGenerator::global()->bounded(height() - 50);
        fly2->setGeometry(x2, y2, 50, 50);
        flies.append(fly2);
        fly2->show();
    }
    else if (level == 3)
    {

        for (int i = 0; i < 2; ++i)
        {
            Fly *fly = new Level2Fly(this);
            int x = QRandomGenerator::global()->bounded(width() - 50);
            int y = QRandomGenerator::global()->bounded(height() - 50);
            fly->setGeometry(x, y, 50, 50);
            flies.append(fly);
            fly->show();
        }

        frog = new Frog(this);
        frog->setGeometry(50, 50, 100, 100);
        frog->show();

        QTimer *frogMoveTimer = new QTimer(this);
        connect(frogMoveTimer, &QTimer::timeout, this, &CatchFlyGame::moveFrogSlowly);
        frogMoveTimer->start(200);
    }

    timer->start(100);
}

void CatchFlyGame::moveFlies()
{
    for (Fly *fly : flies) {
        if (level == 3 && fly->geometry().intersects(door->geometry())) {
            QMessageBox::information(this, "Game Over", "The fly escaped through the door!");
            close();
            return;
        }

        fly->moveRandomly();

        if (fly->isInTrap(trap->geometry())) {
            timer->stop();
            startLevel(level + 1);
            return;
        }
    }

    if (level == 3 && frog) {
        frog->tryToCatchFly(flies);
        if (frog->hasCaughtFly())
        {
            QMessageBox::information(this, "Game Over", "The frog caught the fly!");
            close();
        }
    }
}


void CatchFlyGame::moveFrogSlowly()
{
    if (frog) {
        int newX = frog->x() + QRandomGenerator::global()->bounded(-20, 21);
        int newY = frog->y() + QRandomGenerator::global()->bounded(-20, 21);

        newX = qMax(0, qMin(newX, width() - frog->width()));
        newY = qMax(0, qMin(newY, height() - frog->height()));

        frog->move(newX, newY);
    }
}


void CatchFlyGame::updateScore()
{
    scoreLabel->setText("Score: " + QString::number(score));
}
