#include <QApplication>

#include "catchflygame.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CatchFlyGame game;
    game.show();

    return app.exec();
}
