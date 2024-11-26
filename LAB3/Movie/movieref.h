#ifndef MOVIEREF_H
#define MOVIEREF_H

#include "movie.h"

class MovieRef {
public:
    MovieRef(Movie* moviePtr);

    bool setMovieTitle(string newTitle);
    string getMovieTitle();

    bool setMovieDirector(string newDirector);
    string getMovieDirector();

    bool setMovieYear(int newYear);
    int getMovieYear();

    bool setMovieDuration(int newDuration);
    int getMovieDuration();

private:
    Movie* movie; // Посилання на Movie
};

#endif // MOVIEREF_H
