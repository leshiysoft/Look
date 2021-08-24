#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include "anchor.h"

class Shape
{
public:
    Shape();

    virtual void draw(QPainter* painter) = 0;
    virtual QVector<Anchor> getAnchors() = 0;
    virtual int basePointsCount() = 0;
    virtual void setPoint(int n, QPoint p) = 0;
};

#endif // SHAPE_H
