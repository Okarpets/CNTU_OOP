#include "set.h"

Set::Set() {}

Set::Set(string elems)
{
    for (char elem : elems)
    {
        if (!contains(elem))
        {
            elements.push_back(elem);
        }
    }
}

bool Set::contains(char checkElem) const
{
    for (char elem : elements)
    {
        if (elem == checkElem)
        {
            return true;
        }
    }
    return false;
}

Set Set::operator+(const Set& otherSet) const
{
    Set result = *this;
    for (char elem : otherSet.elements)
    {
        if (!result.contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    return result;
}

Set Set::operator*(const Set& otherSet) const
{
    Set result;
    for (char elem : elements)
    {
        if (otherSet.contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    return result;
}

Set Set::operator-(const Set& otherSet) const
{
    Set result;
    for (char elem : elements)
    {
        if (!otherSet.contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    return result;
}

Set Set::operator^(const Set& otherSet) const
{
    Set result;
    for (char elem : elements)
    {
        if (!otherSet.contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    for (char elem : otherSet.elements)
    {
        if (!contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    return result;
}

ostream& operator<<(ostream& os, const Set& set)
{
    os << "{ ";
    for (char elem : set.elements) {
        os << elem << " ";
    }
    os << "}";
    return os;
}
