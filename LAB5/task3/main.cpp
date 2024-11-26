#include <QCoreApplication>
#include "rectangle.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try {
        Rectangle rect1(10, 5);
        Rectangle rect2(7, 3);
        Rectangle rect3(10, 5);

        Rectangle unionRect = rect1 + rect2;
        cout << "Union rect1 and rect2: " << unionRect << endl;

        Rectangle diffRect = rect1 - rect2;
        cout << "Difference rect1 and rect2: " << diffRect << endl;

        Rectangle scaledRect = rect1 * 2;
        cout << "Scaling rect1 by factor 2: " << scaledRect << endl;

        Rectangle reducedRect = rect1 / 2;
        cout << "Reducing rect1 by divisor 2: " << reducedRect << endl;

        cout << "rect1 is equal to rect3: " << (rect1 == rect3 ? "true" : "false") << endl;

        cout << "rect1 is not equal to rect2: " << (rect1 != rect2 ? "true" : "false") << endl;

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return a.exec();
}
