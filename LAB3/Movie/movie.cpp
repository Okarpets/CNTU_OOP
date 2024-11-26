#include "movie.h"

Movie::Movie() {}

bool Movie::setTitle(string newTitle)
{
    if (checkStrings(newTitle))
    {
        this->title = newTitle;
        return true;
    }
    return false;
}

bool Movie::setDirector(string newDirector)
{
    if (checkStrings(newDirector))
    {
        this->director = newDirector;
        return true;
    }
    return false;
}

bool Movie::setYear(int newYear)
{
    if (checkInts(newYear))
    {
        this->year = newYear;
        return true;
    }
    return false;
}

bool Movie::setDuration(int newDuration)
{
    if (checkInts(newDuration))
    {
        this->duration = newDuration;
        return true;
    }
    return false;
}

bool Movie::checkStrings(string checkString)
{
    if (checkString.length() > 0)
    {
        return true;
    }
    return false;
}

bool Movie::checkInts(int checkInt)
{
    if (checkInt > 0)
    {
        return true;
    }
    return false;
}
