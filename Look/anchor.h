#ifndef ANCHOR_H
#define ANCHOR_H

#include <QPainter>
#include <QPoint>

class Anchor
{
public:
    Anchor(){};
    Anchor(int _x, int _y);
    int x, y;
    void draw(QPainter* painter);
    QPoint toPoint();
};

#endif // ANCHOR_H
