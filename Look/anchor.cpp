#include "anchor.h"

Anchor::Anchor(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Anchor::draw(QPainter* painter)
{
    painter->drawRect(x-5, y-5, 10,10);
}

QPoint Anchor::toPoint()
{
    return QPoint(x, y);
}
