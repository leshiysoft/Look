#include "anchorgetter.h"

#include "model.h"

AnchorGetter::AnchorGetter()
{
    Model::inst().runOverShapes(this);
}

void AnchorGetter::visit(QVector<Shape *> shapes)
{
    anchors.clear();
    foreach(Shape* shape, shapes)
    {
        anchors.append(shape->getAnchors());
    }
}

bool AnchorGetter::getNearestAnchor(QPoint point, Anchor& _anchor)
{
    int distance = 100;
    bool result = false;
    foreach(Anchor anchor, anchors)
    {
        int theDistance = ((point.x() - anchor.x) * (point.x() - anchor.x)) + ((point.y() - anchor.y) * (point.y() - anchor.y));
        if (theDistance < distance){
            distance = theDistance;
            result = true;
            _anchor = anchor;
        }
    }
    return result;
}
