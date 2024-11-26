#include <QRandomGenerator>

#include "frog.h"
#include "fly.h"

Frog::Frog(QWidget *parent)
    : QLabel(parent), caughtFly(false)
{
    setPixmap(QPixmap(":/photo/frog.png").scaled(100, 100, Qt::KeepAspectRatio));
}

bool Frog::hasCaughtFly()
{
    return caughtFly;
}

void Frog::tryToCatchFly(QList<Fly*> flies)
{
    for (Fly *fly : flies)
    {
        if (this->geometry().intersects(fly->geometry()))
        {
            caughtFly = true;
            fly->hide();
            break;
        }
    }
}
