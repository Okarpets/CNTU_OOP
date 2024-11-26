#ifndef GUITAR_H
#define GUITAR_H

#include "instrument.h"

class Guitar : public Instrument {
public:
    Guitar(QString name, double price);

    QString getDescription() override;
    Guitar();
};

#endif // GUITAR_H
