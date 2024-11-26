#include "instrument.h"

Instrument::Instrument(QString name, QString type, double price)
    : name(name), type(type), price(price) {}

QString Instrument::getName()
{
    return name;
}

QString Instrument::getType()
{
    return type;
}

double Instrument::getPrice()
{
    return price;
}

QString Instrument::getDescription()
{
    return QString("%1 (%2) - $%3").arg(name).arg(type).arg(price);
}

Instrument::Instrument() {}
