#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
public:
    Rectangle(int width = 1, int height = 1);
    Rectangle(Rectangle &other);
    ~Rectangle();

    Rectangle operator+(Rectangle &other);
    Rectangle operator-(Rectangle &other);
    Rectangle operator*(int factor);
    Rectangle operator/(int divisor);

    bool operator==(Rectangle &other);
    bool operator!=(Rectangle &other);

    friend std::ostream &operator<<(std::ostream &out, Rectangle &rect);

private:
    int width;
    int height;
};

#endif // RECTANGLE_H
