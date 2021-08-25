#ifndef CIRCLE3SHAPE_H
#define CIRCLE3SHAPE_H

#include "shape.h"

class Circle3Shape : public Shape
{
public:
    Circle3Shape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QPoint center();
    int radius();
    QPoint point1;
    QPoint point2;
    QPoint point3;
};

#endif // CIRCLE3SHAPE_H
