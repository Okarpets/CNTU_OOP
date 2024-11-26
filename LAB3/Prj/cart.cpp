#include "cart.h"

Cart::Cart() {}

void Cart::addProductFrom(Product *product)
{
    this->products.push_back(product);
}

void Cart::deleteProductFrom(Product& delProduct) {
    string delName = delProduct.getProductName();

    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getProductName() == delName) {
            delete *it;
            products.erase(it);
            return;
        }
    }
}

float Cart::getAllCosts()
{
    float allCost = 0;
    for (auto& product : this->products) {
        allCost += product->getProductCost();
    }
    return allCost;
}

vector<Product*> Cart::getAllProductFrom()
{
    return this->products;
}
