#include "circleshape.h"

CircleShape::CircleShape()
{
    radius = 0;
}

void CircleShape::draw(QPainter* painter)
{
    painter->drawEllipse(center, radius, radius);
}

QVector<Anchor> CircleShape::getAnchors()
{
    QVector<Anchor> result;
    result.resize(5);
    result[0].x = center.x();
    result[0].y = center.y() + 1;
    result[0].y = center.y();
    result[1].x = center.x() + radius;
    result[1].y = center.y();
    result[2].x = center.x();
    result[2].y = center.y() + radius;
    result[3].x = center.x();
    result[3].y = center.y() - radius;
    result[4].x = center.x() - radius;
    result[4].y = center.y();
    return result;
}

int CircleShape::basePointsCount()
{
    return 2;
}

void CircleShape::setPoint(int n, QPoint p)
{
    if (n == 1){
        center = p;
    } else if (n == 2){
        radius = sqrt(QPoint::dotProduct(center - p, center - p));
    }
}
