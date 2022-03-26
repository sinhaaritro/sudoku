#ifndef POINT_2D_H
#define POINT_2D_H

class Point2D
{
public:
    Point2D();
    Point2D(int p_x, int p_y);
    int getX();
    int getY();
    friend bool operator<(const Point2D &p_point1, const Point2D &p_point2);
    friend bool operator==(const Point2D &p_point1, const Point2D &p_point2);

private:
    int x;
    int y;
};

#endif