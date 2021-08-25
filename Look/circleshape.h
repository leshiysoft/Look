#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "shape.h"

class CircleShape : public Shape
{
public:
    CircleShape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QPoint center;
    int radius;
};

#endif // CIRCLESHAPE_H
