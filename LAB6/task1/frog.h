#ifndef FROG_H
#define FROG_H

#include <QLabel>

#include "fly.h"

class Frog : public QLabel {
    Q_OBJECT

public:
    Frog(QWidget *parent = nullptr);

    bool hasCaughtFly();

    void tryToCatchFly(QList<Fly*> flies);

private:
    bool caughtFly;
};


#endif // FROG_H
