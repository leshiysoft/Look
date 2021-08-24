#ifndef MODEL_H
#define MODEL_H

#include "shape.h"
#include "modelvisitor.h"

class Model final
{
public:
    static Model& inst();
    void runOverShapes(ModelVisitor* modelVisitor);
    void addShape(Shape* shape);
private:
    Model(){};
    QVector<Shape*> shapes;
};

#endif // MODEL_H
