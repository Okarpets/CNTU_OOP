#include "movieadvanceddetails.h"
#include "moviedetails.h"
#include <iostream>

using namespace std;

MovieAdvancedDetails::MovieAdvancedDetails() : MovieDetails() {}

void MovieAdvancedDetails::printMovieInfo() {
    cout << "Title: " << getMovieTitle() << std::endl;
    cout << "Director: " << getMovieDirector() << std::endl;
    cout << "Year: " << getMovieYear() << std::endl;
    cout << "Duration: " << getMovieDuration() << " minutes" << std::endl;
}
