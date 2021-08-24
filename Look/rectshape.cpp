#include "rectshape.h"

RectShape::RectShape()
{

}

void RectShape::draw(QPainter* painter)
{
    painter->drawRect(rect);
}

QVector<Anchor> RectShape::getAnchors()
{
    QVector<Anchor> result;
    result.resize(4);
    result[0].x = rect.left();
    result[0].y = rect.top();
    result[1].x = rect.right()+1;
    result[1].y = rect.top();
    result[2].x = rect.right()+1;
    result[2].y = rect.bottom()+1;
    result[3].x = rect.left();
    result[3].y = rect.bottom()+1;
    return result;
}

int RectShape::basePointsCount()
{
    return 2;
}

void RectShape::setPoint(int n, QPoint p)
{
    if (n == 1){
        rect.setX(p.x());
        rect.setY(p.y());
        rect.setWidth(0);
        rect.setHeight(0);
    } else if (n == 2){
        rect.setWidth(p.x() - rect.x());
        rect.setHeight(p.y() - rect.y());
    }
}
