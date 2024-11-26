#include "rectangle.h"
#include <stdexcept>

using namespace std;

Rectangle::Rectangle(int width, int height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Width and height must be positive int.");
    }
}

Rectangle::Rectangle(Rectangle &other) : width(other.width), height(other.height) {}

Rectangle::~Rectangle() {}

Rectangle Rectangle::operator+(Rectangle &other) {
    int newWidth = max(this->width, other.width);
    int newHeight = max(this->height, other.height);
    return Rectangle(newWidth, newHeight);
}

Rectangle Rectangle::operator-(Rectangle &other) {
    int newWidth = max(0, this->width - other.width);
    int newHeight = max(0, this->height - other.height);
    return Rectangle(newWidth, newHeight);
}

Rectangle Rectangle::operator*(int factor) {
    return Rectangle(this->width * factor, this->height * factor);
}

Rectangle Rectangle::operator/(int divisor) {
    if (divisor <= 0) throw invalid_argument("Divisor must be a positive int.");
    return Rectangle(this->width / divisor, this->height / divisor);
}

bool Rectangle::operator==(Rectangle &other) {
    return this->width == other.width && this->height == other.height;
}

bool Rectangle::operator!=(Rectangle &other) {
    return !(*this == other);
}

ostream &operator<<(ostream &out, Rectangle &rect) {
    out << "Rectangle(" << rect.width << " x " << rect.height << ")";
    return out;
}
