#include "moviedetails.h"

MovieDetails::MovieDetails() {}

bool MovieDetails::setMovieTitle(string newTitle) {
    return movie.setTitle(newTitle);
}

string MovieDetails::getMovieTitle() {
    return movie.getTitle();
}

bool MovieDetails::setMovieDirector(string newDirector) {
    return movie.setDirector(newDirector);
}

string MovieDetails::getMovieDirector() {
    return movie.getDirector();
}

bool MovieDetails::setMovieYear(int newYear) {
    return movie.setYear(newYear);
}

int MovieDetails::getMovieYear() {
    return movie.getYear();
}

bool MovieDetails::setMovieDuration(int newDuration) {
    return movie.setDuration(newDuration);
}

int MovieDetails::getMovieDuration() {
    return movie.getDuration();
}

