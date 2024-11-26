#include "fly.h"
#include <QRandomGenerator>

Fly::Fly(QWidget *parent) : QLabel(parent), speed(5) {}

void Fly::moveRandomly()
{
    int dx = QRandomGenerator::global()->bounded(-speed, speed);
    int dy = QRandomGenerator::global()->bounded(-speed, speed);

    int newX = x() + dx;
    int newY = y() + dy;

    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX + width() > parentWidget()->width()) newX = parentWidget()->width() - width();
    if (newY + height() > parentWidget()->height()) newY = parentWidget()->height() - height();

    move(newX, newY);
}

bool Fly::isInTrap(QRect trapRect)
{
    return this->geometry().intersects(trapRect);
}

Level1Fly::Level1Fly(QWidget *parent) : Fly(parent)
{
    setPixmap(QPixmap(":/photo/fly.png").scaled(50, 50, Qt::KeepAspectRatio));
    speed = 5;
}

void Level1Fly::moveRandomly()
{
    Fly::moveRandomly();
}

Level2Fly::Level2Fly(QWidget *parent) : Fly(parent)
{
    setPixmap(QPixmap(":/photo/fly2.png").scaled(50, 50, Qt::KeepAspectRatio));
    speed = 8;
}

void Level2Fly::moveRandomly()
{
    Fly::moveRandomly();
}

void Level2Fly::moveToWindow(QRect windowRect)
{
    int dx = (windowRect.x() - x()) / 10;
    int dy = (windowRect.y() - y()) / 10;
    move(x() + dx, y() + dy);
}
