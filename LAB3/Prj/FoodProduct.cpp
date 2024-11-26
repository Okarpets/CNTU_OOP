#include "FoodProduct.h"

FoodProduct::FoodProduct() {}

void FoodProduct::setExpiryDate(string expiryDate)
{
    this->expiryDate = expiryDate;
}

string FoodProduct::getExpiryDate()
{
    return this->expiryDate;
}
