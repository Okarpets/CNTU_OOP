#ifndef MOVIE_DETAILS_H
#define MOVIE_DETAILS_H

#include "movie.h"

class MovieDetails {
public:
    MovieDetails();

    bool setMovieTitle(string newTitle);
    string getMovieTitle();

    bool setMovieDirector(string newDirector);
    string getMovieDirector();

    bool setMovieYear(int newYear);
    int getMovieYear();

    bool setMovieDuration(int newDuration);
    int getMovieDuration();

private:
    Movie movie;
};

#endif // MOVIE_DETAILS_H
