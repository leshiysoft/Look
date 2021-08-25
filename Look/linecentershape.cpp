#include "linecentershape.h"

LineCenterShape::LineCenterShape()
{

}

void LineCenterShape::draw(QPainter* painter)
{
    painter->drawLine(point1, point2);
}

QVector<Anchor> LineCenterShape::getAnchors()
{
    QVector<Anchor> result;
    result.resize(3);
    result[0].x = point1.x();
    result[0].y = point1.y();
    result[1].x = point2.x();
    result[1].y = point2.y();
    result[2].x = (point1.x() + point2.x())/2;
    result[2].y = (point1.y() + point2.y())/2;
    return result;
}

int LineCenterShape::basePointsCount()
{
    return 2;
}

void LineCenterShape::setPoint(int n, QPoint p)
{
    if (n == 1){
        center = p;
    } else if (n == 2){
        int xSide = p.x() - center.x();
        int ySide = p.y() - center.y();
        point1.setX(center.x() + xSide);
        point1.setY(center.y() + ySide);
        point2.setX(center.x() - xSide);
        point2.setY(center.y() - ySide);
    }
}
