#ifndef CART_H
#define CART_H

#include <string>
#include <vector>

#include "product.h"

using namespace std;

class Cart
{
    public:
        Cart();
        void addProductFrom(Product *product);
        void deleteProductFrom(Product& delProduct);
        float getAllCosts();

        vector<Product*> getAllProductFrom();
    private:
        vector<Product*> products;
        float productsCost;
};

#endif // CART_H
