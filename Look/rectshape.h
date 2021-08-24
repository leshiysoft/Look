#ifndef RECTSHAPE_H
#define RECTSHAPE_H

#include "shape.h"

#include <QRect>

class RectShape : public Shape
{
public:
    RectShape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QRect rect;
};

#endif // RECTSHAPE_H
