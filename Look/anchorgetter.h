#ifndef ANCHORGETTER_H
#define ANCHORGETTER_H

#include "modelvisitor.h"
#include "shape.h"

class AnchorGetter : public ModelVisitor
{
public:
    AnchorGetter();
    virtual void visit(QVector<Shape*>);
    bool getNearestAnchor(QPoint point, Anchor& _anchor);
    QVector<Anchor> anchors;
};

#endif // ANCHORGETTER_H
