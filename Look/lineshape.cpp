#include "lineshape.h"

LineShape::LineShape()
{

}

void LineShape::draw(QPainter* painter)
{
    painter->drawLine(point1, point2);
}

QVector<Anchor> LineShape::getAnchors()
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

int LineShape::basePointsCount()
{
    return 2;
}

void LineShape::setPoint(int n, QPoint p)
{
    if (n == 1){
        point1 = p;
        point2 = p;
    } else if (n == 2){
        point2 = p;
    }
}
