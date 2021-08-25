#ifndef LINESHAPE_H
#define LINESHAPE_H

#include "shape.h"

class LineShape : public Shape
{
public:
    LineShape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QPoint point1;
    QPoint point2;
};

#endif // LINESHAPE_H
