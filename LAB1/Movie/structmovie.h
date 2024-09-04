#ifndef STRUCTMOVIE_H
#define STRUCTMOVIE_H

#include <string>

using namespace std;

struct MovieStruct {
    string title;
    string director;
    int year;
    int duration;
};

bool setTitle(MovieStruct& movie, const string& newTitle);
string getTitle(const MovieStruct& movie);

bool setDirector(MovieStruct& movie, const string& newDirector);
string getDirector(const MovieStruct& movie);

bool setYear(MovieStruct& movie, int newYear);
int getYear(const MovieStruct& movie);

bool setDuration(MovieStruct& movie, int newDuration);
int getDuration(const MovieStruct& movie);

bool checkStrings(const string& checkString);
bool checkInts(int checkInt);

#endif // STRUCTMOVIE_H
