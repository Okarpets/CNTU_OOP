#include <iostream>

#include "set.h"

using namespace std;

int main()
{
    Set set1("abc");
    Set set2("bcd");

    Set unionSet = set1 + set2;
    Set intersectionSet = set1 * set2;
    Set differenceSet = set1 - set2;
    Set symmetricDifferenceSet = set1 ^ set2;

    cout << "Union: " << unionSet << endl;
    cout << "Intersection: " << intersectionSet << endl;
    cout << "Difference: " << differenceSet << endl;
    cout << "Symmetric Difference: " << symmetricDifferenceSet << endl;

    return 0;
}
