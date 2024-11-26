#include <QCoreApplication>
#include "movie.h"
#include "set.h"

Set buildSymmetricDifference(Set set1, Set set2) {
    return set1.symmetricDifference(set2);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char order = '\0';
    int userInputInt;
    string userInputStr;
    Movie *defaultMovie = new Movie();
    Movie *params = new Movie("Cyberpunk 2077", "CDPR", 3600, 2077);
    Movie *copy = new Movie(*params);

    cout << "Default/Param/Copy/Set (D/P/C/S))?" << endl;
    cin >> order;
    cin.ignore();
    switch (order)
    {
        case 'd':
        case 'D':
            cout << "Defalut Title: " << defaultMovie->getTitle() << endl;
            cout << "Defalut Year: " << defaultMovie->getYear() << endl;
            cout << "Defalut Director: " << defaultMovie->getDirector() << endl;
            cout << "Defalut Duration: " << defaultMovie->getDuration() << endl;
            break;

        case 'p':
        case 'P':

            cout << "Defalut Title: " << params->getTitle() << endl;
            cout << "Defalut Year: " << params->getYear() << endl;
            cout << "Defalut Director: " << params->getDirector() << endl;
            cout << "Defalut Duration: " << params->getDuration() << endl;
            break;

        case 'c':
        case 'C':

            cout << "Defalut Title: " << copy->getTitle() << endl;
            cout << "Defalut Year: " << copy->getYear() << endl;
            cout << "Defalut Director: " << copy->getDirector() << endl;
            cout << "Defalut Duration: " << copy->getDuration() << endl;

        case 's':
        case 'S':
            Set set1("abcfgnrfhegwrghgtrhgdbfdbdf");
            Set set2("cdefgwfgwfbfgnaaaaaaaaaaaaaaaaaffffpbn");

            cout << "SET 1: ";
            set1.print();

            cout << "SET 2: ";
            set2.print();

            Set symDiff = buildSymmetricDifference(set1, set2);
            cout << "SYMMETRIC DIFFERENCE: ";
            symDiff.print();

    }

    cout << "DESTRUCT:" << endl << endl;
    defaultMovie->~Movie();
    copy->~Movie();
    params->~Movie();
    return 0;
}
