#include "product.h"

Product::Product() {}

void Product::setProductName(string productName)
{
    this->productName = productName;
}

void Product::setProductCost(float productCost)
{
    this->productCost = productCost;
}

string Product::getProductName()
{
    return this->productName;
}

float Product::getProductCost()
{
    return this->productCost;
}
