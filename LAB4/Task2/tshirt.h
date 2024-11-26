#ifndef TSHIRT_H
#define TSHIRT_H

#include "clothing.h"

class TShirt : public Clothing {
private:
    QString material;
    QString collarType;

public:
    TShirt(QString name, QString size, QString color, QString material, QString collarType);

    void setMaterial(QString material);
    QString getMaterial();

    void setCollarType(QString collarType);
    QString getCollarType();

    void printInfo() override;
};

#endif // TSHIRT_H
