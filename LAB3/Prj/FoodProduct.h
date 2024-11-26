#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include <string>

#include "product.h"

using namespace std;

class FoodProduct : public Product
{
    public:
        FoodProduct();
        void setExpiryDate(string);
        string getExpiryDate();

    private:
        string expiryDate;
};

#endif // FOODPRODUCT_H
