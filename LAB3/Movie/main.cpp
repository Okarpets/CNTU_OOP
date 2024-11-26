#include <QCoreApplication>
#include "movie.h"
#include "movieadvanceddetails.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MovieAdvancedDetails *details = new MovieAdvancedDetails();
    details->setMovieDirector("Hidetaka Miyazaki");
    details->setMovieDuration(180000);
    details->setMovieTitle("Sekiro: Shadows Die Twice");
    details->setMovieYear(2019);

    details->printMovieInfo();
    return a.exec();
}
