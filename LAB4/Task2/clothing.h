#ifndef CLOTHING_H
#define CLOTHING_H

#include <QString>
#include <iostream>
#include <stdexcept>

using namespace std;

class Clothing {
protected:
    QString name;
    QString size;
    QString color;

public:
    Clothing(QString name, QString size, QString color);
    virtual ~Clothing() = default;

    virtual void setName(QString name);
    virtual QString getName();

    virtual void setSize(QString size);
    virtual QString getSize();

    virtual void setColor(QString color);
    virtual QString getColor();

    virtual void printInfo();
};

#endif // CLOTHING_H
