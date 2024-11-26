#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    public:
        Product();
        void setProductName(string);
        void setProductCost(float);

        string getProductName();
        float getProductCost();

    protected:
        string productName;
        float productCost;

};

#endif // PRODUCT_H
