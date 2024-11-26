#ifndef FLY_H
#define FLY_H

#include <QLabel>
#include <QTimer>
#include <QWidget>

class Fly : public QLabel {
    Q_OBJECT
public:
    Fly(QWidget *parent = nullptr);
    virtual void moveRandomly();
    bool isInTrap(const QRect &trapRect);

protected:
    int speed;
};

class Level1Fly : public Fly {
    Q_OBJECT
public:
    Level1Fly(QWidget *parent = nullptr);
    void moveRandomly() override;
};

class Level2Fly : public Fly {
    Q_OBJECT
public:
    Level2Fly(QWidget *parent = nullptr);
    void moveRandomly() override;
    void moveToWindow(const QRect &windowRect);
};

#endif // FLY_H
