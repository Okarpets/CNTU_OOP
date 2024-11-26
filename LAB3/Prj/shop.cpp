#include "shop.h"
#include "product.h"

Shop::Shop() {}

void Shop::setShopName(string shopName)
{
    this->shopName = shopName;
}

void Shop::setShopAddress(string shopAddress)
{
    this->shopAddress = shopAddress;
}

void Shop::setShopProducts(vector<Product*> products)
{
    this->products = products;
}

string Shop::getShopName()
{
    return this->shopName;
}

string Shop::getShopAddress()
{
    return this->shopAddress;
}

vector<Product*> Shop::getShopProducts()
{
    return this->products;
}
