#include "shipment.h"

Shipment::Shipment(int id, QString sender, QString receiver, double weight, QString type)
    : id(id), sender(sender), receiver(receiver), weight(weight), type(type) {}

int Shipment::getId() const {
    return id;
}

QString Shipment::getSender() const {
    return sender;
}

QString Shipment::getReceiver() const {
    return receiver;
}

double Shipment::getWeight() const {
    return weight;
}

QString Shipment::getType() const {
    return type;
}

void Shipment::setSender(QString newSender)
{
    sender = newSender;
}

void Shipment::setReceiver(QString newReceiver)
{
    sender = newReceiver;
}

void Shipment::setWeight(double newWeight) {
    weight = newWeight;
}

void Shipment::setType(QString newType) {
    type = newType;
}
