#include "arrestcockroach.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ArrestCockroach w;
    w.show();

    return app.exec();
}
