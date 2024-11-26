#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>

class Instrument {
protected:
    QString name;
    QString type;
    double price;

public:
    Instrument(QString name, QString type, double price);

    QString getName();
    QString getType();
    double getPrice();

    virtual QString getDescription();

    virtual ~Instrument() {}
    Instrument();
};

#endif // INSTRUMENT_H
