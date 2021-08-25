#ifndef LINECENTERSHAPE_H
#define LINECENTERSHAPE_H

#include "shape.h"

class LineCenterShape : public Shape
{
public:
    LineCenterShape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QPoint point1;
    QPoint point2;
    QPoint center;
};

#endif // LINECENTERSHAPE_H
