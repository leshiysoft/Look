#include "rectcentershape.h"

RectCenterShape::RectCenterShape()
{

}

void RectCenterShape::draw(QPainter* painter)
{
    painter->drawRect(rect);
}

QVector<Anchor> RectCenterShape::getAnchors()
{
    QVector<Anchor> result;
    result.resize(5);
    result[0].x = rect.left();
    result[0].y = rect.top();
    result[1].x = rect.right()+1;
    result[1].y = rect.top();
    result[2].x = rect.right()+1;
    result[2].y = rect.bottom()+1;
    result[3].x = rect.left();
    result[3].y = rect.bottom()+1;
    result[4].x = (rect.left()+rect.right())/2;
    result[4].y = (rect.top()+rect.bottom())/2;
    return result;
}

int RectCenterShape::basePointsCount()
{
    return 2;
}

void RectCenterShape::setPoint(int n, QPoint p)
{
    if (n == 1){
        center = p;
    } else if (n == 2){
        int xSide = p.x() - center.x();
        int ySide = p.y() - center.y();
        rect.setX(center.x() - xSide);
        rect.setY(center.y() - ySide);
        rect.setWidth(xSide*2+1);
        rect.setHeight(ySide*2+1);
    }
}
