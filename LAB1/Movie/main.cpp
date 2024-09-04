#include <QCoreApplication>
#include "movie.h"
#include "structmovie.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char order = '\0';
    int userInputInt;
    string userInputStr;

    Movie *movie = new Movie;
    MovieStruct myMovie;


    cout << "OOP/Struct (O/S)?" << endl;
    cin >> order;
    cin.ignore();
    switch (order) {
    case 'o':
    case 'O':

        cout << "Enter Title: " << endl;
        getline(cin, userInputStr);
        if (movie->setTitle(userInputStr))
        {
            cout << "Title " << movie->getTitle() << endl;
        }
        else
        {
            cout << "Invalid Title" << endl;
        }

        //////////////////

        cout << "Enter Director: " << endl;
        getline(cin, userInputStr);
        if (movie->setDirector(userInputStr))
        {
            cout << "Director " << movie->getDirector() << endl;
        }
        else
        {
            cout << "Invalid Director" << endl;
        }

        //////////////////

        cout << "Enter Duration: " << endl;
        cin >> userInputInt;
        if (movie->setDuration(userInputInt))
        {
            cout << "Duration in seconds: " << movie->getDuration() << endl;
        }
        else
        {
            cout << "Invalid Duration" << endl;
        }

        //////////////////

        cout << "Enter Year: " << endl;
        cin >> userInputInt;
        if (movie->setYear(userInputInt))
        {
            cout << "Year: " << movie->getYear() << endl;
        }
        else
        {
            cout << "Invalid Year" << endl;
        }
        return 0;

    case 's':
    case 'S':

        cout << "Enter Title: " << endl;
        getline(cin, userInputStr);
        if (setTitle(myMovie, userInputStr)) {
            cout << "Title: " << getTitle(myMovie) << endl;
        } else {
            cout << "Invalid Title" << endl;
        }

        cout << "Enter Director: " << endl;
        getline(cin, userInputStr);
        if (setDirector(myMovie, userInputStr)) {
            cout << "Director: " << getDirector(myMovie) << endl;
        } else {
            cout << "Invalid Director" << endl;
        }

        cout << "Enter Duration: " << endl;
        cin >> userInputInt;
        if (setDuration(myMovie, userInputInt)) {
            cout << "Duration in seconds: " << getDuration(myMovie) << endl;
        } else {
            cout << "Invalid Duration" << endl;
        }

        cout << "Enter Year: " << endl;
        cin >> userInputInt;
        if (setYear(myMovie, userInputInt)) {
            cout << "Year: " << getYear(myMovie) << endl;
        } else {
            cout << "Invalid Year" << endl;
        }
        return 0;

    default:
        cout << "Invalid order" << endl;
        delete movie;
        return 0;
    }


    delete movie;
    return a.exec();
}
