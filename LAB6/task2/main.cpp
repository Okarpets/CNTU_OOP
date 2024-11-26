#include <QCoreApplication>

#include "musicstore.h"
#include "guitar.h"
#include "drum.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MusicStore<Instrument> store;

    store.addInstrument(new Guitar("Fender Stratocaster", 1200.00));
    store.addInstrument(new Drum("Yamaha Drum Set", 800.00));
    store.addInstrument(new Guitar("Gibson Les Paul", 1500.00));

    qDebug() << "All Instruments:";
    store.listAllInstruments();

    qDebug() << "\nGuitars:";
    auto guitars = store.getInstrumentsByType("Guitar");
    for (const auto& guitar : guitars) 
    {
        qDebug() << guitar->getDescription();
    }

    store.removeInstrument("Fender Stratocaster");
    qDebug() << "\nAfter removing Fender Stratocaster:";
    store.listAllInstruments();

    return a.exec();
}
