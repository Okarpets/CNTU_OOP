#include "tshirt.h"

TShirt::TShirt(QString name, QString size, QString color, QString material, QString collarType)
    : Clothing(name, size, color), material(material), collarType(collarType) {}

void TShirt::setMaterial(QString material) {
    if (material.isEmpty()) {
        throw invalid_argument("Material cant be empty");
    }
    this->material = material;
}

QString TShirt::getMaterial() {
    return material;
}

void TShirt::setCollarType(QString collarType) {
    if (collarType.isEmpty()) {
        throw invalid_argument("Collar type cant be empty");
    }
    this->collarType = collarType;
}

QString TShirt::getCollarType() {
    return collarType;
}

void TShirt::printInfo() {
    cout << "T-Shirt: " << name.toStdString()
         << ", Size: " << size.toStdString()
         << ", Color: " << color.toStdString()
         << ", Material: " << material.toStdString()
         << ", Collar Type: " << collarType.toStdString() << endl;
}
