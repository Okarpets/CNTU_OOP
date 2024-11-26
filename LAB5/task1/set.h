#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Set {
private:
    vector<char> elements;

public:
    Set();
    Set(string elems);

    bool contains(char checkElem) const;

    Set operator+(const Set& otherSet) const;
    Set operator*(const Set& otherSet) const;
    Set operator-(const Set& otherSet) const;
    Set operator^(const Set& otherSet) const;

    friend ostream& operator<<(ostream& os, const Set& set);
};

#endif // SET_H
