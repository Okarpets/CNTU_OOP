#include "clothing.h"

Clothing::Clothing(QString name, QString size, QString color) {
    setName(name);
    setSize(size);
    setColor(color);
}

void Clothing::setName(QString name) {
    if (name.isEmpty()) {
        throw invalid_argument("Name cant be empty");
    }
    this->name = name;
}

QString Clothing::getName() {
    return name;
}

void Clothing::setSize(QString size) {
    if (size.isEmpty()) {
        throw invalid_argument("Size cant be empty");
    }
    this->size = size;
}

QString Clothing::getSize() {
    return size;
}

void Clothing::setColor(QString color) {
    if (color.isEmpty()) {
        throw invalid_argument("Color cant be empty");
    }
    this->color = color;
}

QString Clothing::getColor() {
    return color;
}

void Clothing::printInfo()
{

}
