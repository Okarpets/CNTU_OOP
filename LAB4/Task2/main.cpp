#include <QCoreApplication>
#include "tshirt.h"
#include "pants.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TShirt tshirt("Nike T-Shirt", "M", "Red", "Cotton", "Round Neck");
    Pants pants("Levi's Jeans", "L", "Blue", "Denim", "Zipper");

    tshirt.printInfo();
    pants.printInfo();

    return a.exec();
}
