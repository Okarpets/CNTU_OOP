#ifndef CATCHFLYGAME_H
#define CATCHFLYGAME_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include <QList>
#include "fly.h"
#include "frog.h"

class CatchFlyGame : public QMainWindow {
    Q_OBJECT

public:
    CatchFlyGame(QWidget *parent = nullptr);
    void startLevel(int level);

    void moveFrogSlowly();
protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void moveFlies();

private:
    QList<Fly*> flies;
    QLabel *trap;
    QLabel *window;
    QLabel *room;
    QLabel *door;
    Frog *frog;
    QTimer *timer;
    int level;
    int flyCount;
    int score;
    QLabel *scoreLabel;
    void updateScore();
};

#endif // CATCHFLYGAME_H
