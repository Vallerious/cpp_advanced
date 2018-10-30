#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"

class Shape {
private:
    Vector2D center;
protected:
    double area;
public:
    Shape() : center(Vector2D{ 0, 0 }), area(0) {}

    Shape(Vector2D center) : center(center), area(0) {}

    Vector2D getCenter() const {
        return this->center;
    }

    double getArea() const {
        return this->area;
    }
};

#endif // !SHAPE_H