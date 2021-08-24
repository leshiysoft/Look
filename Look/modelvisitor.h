#ifndef MODELVISITOR_H
#define MODELVISITOR_H

#include "shape.h"

class ModelVisitor
{
public:
    ModelVisitor();
    virtual void visit(QVector<Shape*>) = 0;
};

#endif // MODELVISITOR_H
