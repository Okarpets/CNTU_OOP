#ifndef DRUM_H
#define DRUM_H

#include "instrument.h"

class Drum : public Instrument {
public:
    Drum(QString name, double price);

    QString getDescription() override;
    Drum();
};

#endif // DRUM_H
