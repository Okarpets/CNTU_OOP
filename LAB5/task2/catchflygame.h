#ifndef CATCHFLYGAME_H
#define CATCHFLYGAME_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include "fly.h"

class CatchFlyGame : public QMainWindow {
    Q_OBJECT

public:
    CatchFlyGame(QWidget *parent = nullptr);
    void startLevel(int level);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void moveFly();

private:
    Fly *fly;
    QLabel *trap;
    QLabel *window;
    QTimer *timer;
    int level;
};

#endif // CATCHFLYGAME_H
