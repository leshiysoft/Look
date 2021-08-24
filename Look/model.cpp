#include "model.h"

Model& Model::inst()
{
    static Model model;
    return model;
}

void Model::runOverShapes(ModelVisitor* modelVisitor)
{
    modelVisitor->visit(shapes);
}

void Model::addShape(Shape* shape)
{
    shapes.append(shape);
}
