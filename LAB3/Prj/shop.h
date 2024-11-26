#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>

#include "product.h"

using namespace std;

class Shop
{
    public:
        Shop();
        void setShopName(string);
        void setShopAddress(string);
        void setShopProducts(vector<Product*> products);

        string getShopName();
        string getShopAddress();
        vector<Product*> getShopProducts();

    private:
        string shopName;
        string shopAddress;
        vector<Product*> products;
};

#endif // SHOP_H
