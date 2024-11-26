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

bool Set::contains(char checkElem)
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

Set Set::plusSets(Set otherSet)
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

Set Set::intersectionSets(Set otherSet)
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

Set Set::differenceSet(Set otherSet)
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

Set Set::symmetricDifference(Set other)
{
    Set result;
    for (char elem : elements)
    {
        if (!other.contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    for (char elem : other.elements)
    {
        if (!contains(elem))
        {
            result.elements.push_back(elem);
        }
    }
    return result;
}

void Set::print()
{
    cout << "{ ";
    for (char elem : elements) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}
