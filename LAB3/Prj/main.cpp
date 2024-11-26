#include <QCoreApplication>
#include <iostream>
#include "FoodProduct.h"
#include "cart.h"
#include "shop.h"


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cart *cart = new Cart();
    Shop *shop = new Shop();

    for (int index = 0; index < 100; index++) {
        FoodProduct *product = new FoodProduct();
        product->setProductCost(index);
        string productName = ("Apple " + to_string(index));
        product->setProductName(productName);
        string expiryDate = ("Expiry" + to_string(index));
        product->setExpiryDate(expiryDate);
        cart->addProductFrom(product);
    }

    shop->setShopProducts(cart->getAllProductFrom());

    cout << "All cart products info:" << endl;
    for (const auto& product : shop->getShopProducts()) {
        cout << "Product Name: " << product->getProductName() << endl;
        cout << "Product Cost: " << product->getProductCost() << endl;
    }

    cout << "Product Cost: " << cart->getAllCosts() << endl;
    return a.exec();
}
