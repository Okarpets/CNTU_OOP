#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <QString>

class Shipment {
public:
    Shipment(int id, QString sender, QString receiver, double weight, QString type);

    int getId() const;
    QString getSender() const;
    QString getReceiver() const;
    double getWeight() const;
    QString getType() const;

    void setSender(QString newSender);
    void setReceiver(QString newReceiver);
    void setWeight(double newWeight);
    void setType(QString newType);

private:
    int id;
    QString sender;
    QString receiver;
    double weight;
    QString type;
};

#endif // SHIPMENT_H
