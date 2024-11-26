#include "drum.h"

Drum::Drum(QString name, double price)
    : Instrument(name, "Drum", price) {}

QString Drum::getDescription()
{
    return QString("Drum: %1 - $%2").arg(name).arg(price);
}

Drum::Drum() {}
