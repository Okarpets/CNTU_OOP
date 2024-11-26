#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>

using namespace std;

class Set {
private:
    vector<char> elements;

public:
    Set();

    Set(string elems);
    bool contains(char checkElem);
    Set plusSets(Set otherSet);
    Set intersectionSets(Set otherSet);
    Set differenceSet(Set otherSet);
    Set symmetricDifference(Set other);
    void print();
};

#endif // SET_H
