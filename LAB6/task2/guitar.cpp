#include "guitar.h"

Guitar::Guitar(QString name, double price)
    : Instrument(name, "Guitar", price) {}

QString Guitar::getDescription()
{
    return QString("Guitar: %1 - $%2").arg(name).arg(price);
}

Guitar::Guitar() {}
