#ifndef RECTCENTERSHAPE_H
#define RECTCENTERSHAPE_H

#include "shape.h"

class RectCenterShape : public Shape
{
public:
    RectCenterShape();
    void draw(QPainter* painter);
    QVector<Anchor> getAnchors();
    int basePointsCount();
    void setPoint(int n, QPoint p);
    QRect rect;
    QPoint center;
};

#endif // RECTCENTERSHAPE_H
