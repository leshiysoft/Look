#include "circle3shape.h"

Circle3Shape::Circle3Shape()
{

}

void Circle3Shape::draw(QPainter* painter)
{
    painter->drawEllipse(center(), radius(), radius());
}

QVector<Anchor> Circle3Shape::getAnchors()
{
    QVector<Anchor> result;
    result.resize(5);
    result[0].x = center().x();
    result[0].y = center().y();
    result[1].x = center().x() + radius();
    result[1].y = center().y();
    result[2].x = center().x();
    result[2].y = center().y() + radius();
    result[3].x = center().x();
    result[3].y = center().y() - radius();
    result[4].x = center().x() - radius();
    result[4].y = center().y();
    return result;
}

int Circle3Shape::basePointsCount()
{
    return 3;
}

QPoint Circle3Shape::center()
{
    QPoint result;
    int x1 = point1.x();
    int y1 = point1.y();
    int x2 = point2.x();
    int y2 = point2.y();
    int x3 = point3.x();
    int y3 = point3.y();
    int A = x2 - x1;
    int B = y2 - y1;
    int C = x3 - x1;
    int D = y3 - y1;
    int E = A * (x1 + x2) + B * (y1 + y2);
    int F = C * (x1 + x3) + D * (y1 + y3);
    int G = 2 * (A * (y3 - y2) - B * (x3 - x2));
    if (G == 0){
        result = point1;
    } else {
        result.setX((D * E - B * F) / G);
        result.setY((A * F - C * E) / G);
    }
    return result;
}

int Circle3Shape::radius()
{
    return sqrt(QPoint::dotProduct(center() - point1, center() - point1));
}

void Circle3Shape::setPoint(int n, QPoint p)
{
    if (n == 1){
        point1 = p;
        point2 = p;
        point3 = p;
    } else if (n == 2){
        point2 = p;
        QPoint c = point1 + (point2 - point1)/2;
        QPoint v = c - point1;
        QPoint pv(-v.y(), v.x());
        point3 = c + pv;
    } else if (n == 3){
        point3 = p;
    }
}
