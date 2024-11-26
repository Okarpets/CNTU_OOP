#ifndef MUSICSTORE_H
#define MUSICSTORE_H

#include <QList>
#include <QString>
#include <QDebug>

template <typename T>
class MusicStore
{

public:
    void addInstrument(T* instrument)
    {
        instruments.append(instrument);
    }

    void removeInstrument(QString name)
    {
        for (int i = 0; i < instruments.size(); ++i)
        {
            if (instruments[i]->getName() == name)
            {
                delete instruments.takeAt(i);
                return;
            }
        }
    }

    QList<T*> getInstrumentsByType(QString type)
    {
        QList<T*> result;
        for (const auto& instrument : instruments)
        {
            if (instrument->getType() == type)
            {
                result.append(instrument);
            }
        }
        return result;
    }

    void listAllInstruments()
    {
        for (const auto& instrument : instruments)
        {
            qDebug() << instrument->getDescription();
        }
    }

    ~MusicStore()
    {
        qDeleteAll(instruments);
    }

private:
    QList<T*> instruments;

};

#endif // MUSICSTORE_H
