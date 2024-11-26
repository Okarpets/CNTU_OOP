#include "pants.h"

Pants::Pants(QString name, QString size, QString color, QString material, QString fasteningType)
    : Clothing(name, size, color), material(material), fasteningType(fasteningType) {}

void Pants::setMaterial(QString material) {
    if (material.isEmpty()) {
        throw invalid_argument("Material cant be empty");
    }
    this->material = material;
}

QString Pants::getMaterial() {
    return material;
}

void Pants::setFasteningType(QString fasteningType) {
    if (fasteningType.isEmpty()) {
        throw invalid_argument("Fastening type cant be empty");
    }
    this->fasteningType = fasteningType;
}

QString Pants::getFasteningType() {
    return fasteningType;
}

void Pants::printInfo() {
    cout << "Pants: " << name.toStdString()
         << ", Size: " << size.toStdString()
         << ", Color: " << color.toStdString()
         << ", Material: " << material.toStdString()
         << ", Fastening Type: " << fasteningType.toStdString() << endl;
}
