#include "structmovie.h"

bool setTitle(MovieStruct& movie, const string& newTitle) {
    if (checkStrings(newTitle)) {
        movie.title = newTitle;
        return true;
    }
    return false;
}

string getTitle(const MovieStruct& movie) {
    return movie.title;
}

bool setDirector(MovieStruct& movie, const string& newDirector) {
    if (checkStrings(newDirector)) {
        movie.director = newDirector;
        return true;
    }
    return false;
}

string getDirector(const MovieStruct& movie) {
    return movie.director;
}

bool setYear(MovieStruct& movie, int newYear) {
    if (checkInts(newYear)) {
        movie.year = newYear;
        return true;
    }
    return false;
}

int getYear(const MovieStruct& movie) {
    return movie.year;
}

bool setDuration(MovieStruct& movie, int newDuration) {
    if (checkInts(newDuration)) {
        movie.duration = newDuration;
        return true;
    }
    return false;
}

int getDuration(const MovieStruct& movie) {
    return movie.duration;
}

bool checkStrings(const string& checkString) {
    return !checkString.empty();
}

bool checkInts(int checkInt) {
    return checkInt > 0;
}
