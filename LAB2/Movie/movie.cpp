#include "movie.h"

Movie::Movie()
{
    this->setDirector("default");
    this->setTitle("default");
    this->setDuration(1);
    this->setYear(1);
}

Movie::Movie(string newTitle, string newDirector, int newDuration, int newYear)
{
    this->setDirector(newDirector);
    this->setTitle(newTitle);
    this->setDuration(newDuration);
    this->setYear(newYear);
}

Movie::Movie(Movie &copy)
{
    this->setDirector(copy.getDirector());
    this->setTitle(copy.getTitle());
    this->setDuration(copy.getDuration());
    this->setYear(copy.getYear());
}

Movie::~Movie()
{
    cout << "Class Movie has been deleted" << endl;
}

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
