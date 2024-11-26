#include "movieref.h"

MovieRef::MovieRef(Movie* moviePtr) : movie(moviePtr) {}

bool MovieRef::setMovieTitle(string newTitle) {
    return movie->setTitle(newTitle);
}

string MovieRef::getMovieTitle() {
    return movie->getTitle();
}

bool MovieRef::setMovieDirector(string newDirector) {
    return movie->setDirector(newDirector);
}

string MovieRef::getMovieDirector() {
    return movie->getDirector();
}

bool MovieRef::setMovieYear(int newYear) {
    return movie->setYear(newYear);
}

int MovieRef::getMovieYear() {
    return movie->getYear();
}

bool MovieRef::setMovieDuration(int newDuration) {
    return movie->setDuration(newDuration);
}

int MovieRef::getMovieDuration() {
    return movie->getDuration();
}
