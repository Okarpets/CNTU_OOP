#ifndef PANTS_H
#define PANTS_H

#include "clothing.h"

class Pants : public Clothing {
private:
    QString material;
    QString fasteningType;

public:
    Pants(QString name, QString size, QString color, QString material, QString fasteningType);

    void setMaterial(QString material);
    QString getMaterial();

    void setFasteningType(QString fasteningType);
    QString getFasteningType();

    void printInfo() override;
};

#endif // PANTS_H
