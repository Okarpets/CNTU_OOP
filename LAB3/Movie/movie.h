#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie
{
public:
    Movie();

    bool setTitle(string newTitle);
    string getTitle() { return title; }
    bool setDirector(string newDirector);
    string getDirector() { return director; }
    bool setYear(int newYear);
    int getYear() { return year; }
    bool setDuration(int newDuration);
    int getDuration() { return duration; }

private:
    string title;
    string director;
    int year;
    int duration;

    bool checkStrings(string checkString);
    bool checkInts(int checkInt);
};

#endif // MOVIE_H
