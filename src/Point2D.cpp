#include <iostream>

#include "Point2D.h"

Point2D::Point2D() : x(0), y(0){};

Point2D::Point2D(int p_x, int p_y) : x(p_x), y(p_y){};

int Point2D::getX() { return x; }

int Point2D::getY() { return y; }

bool operator<(const Point2D &p_point1, const Point2D &p_point2)
{
    return p_point1.x * 10 + p_point1.y < p_point2.x * 10 + p_point2.y;
}

bool operator==(const Point2D &p_point1, const Point2D &p_point2)
{
    return p_point1.x == p_point2.x && p_point1.y == p_point2.y;
}