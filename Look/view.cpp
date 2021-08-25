#include "view.h"
#include "rectshape.h"
#include "rectcentershape.h"
#include "lineshape.h"
#include "circleshape.h"
#include "circle3shape.h"
#include "linecentershape.h"
#include "anchorgetter.h"

#include <QSizePolicy>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <model.h>

View::View(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    resize(600,600);
    parent->resize(650,650);
    setBackgroundRole(QPalette::Background);
    currentShape = nullptr;
    setMouseTracking(true);
}

void View::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush(QColor(255,255,255));
    QPen pen(QColor(0,0,0));
    painter.setBrush(brush);
    painter.setPen(pen);
    QSize viewSize = size();
    painter.drawRect(QRect(0,0,viewSize.width(),viewSize.height()));

    ShapeDrawer shapeDrawer(&painter);
    Model::inst().runOverShapes(&shapeDrawer);

    if (currentShape)
    {
        Anchor an;
        AnchorGetter anchorGetter;
        if (anchorGetter.getNearestAnchor(lastPoint, an)){
            an.draw(&painter);
        }
        QPen redpen(QColor(255,0,0));
        painter.setPen(redpen);
        currentShape->draw(&painter);
    }
}

void View::mousePressEvent(QMouseEvent *event)
{
    if (currentShape)
    {
        Anchor an;
        AnchorGetter anchorGetter;
        if (anchorGetter.getNearestAnchor(lastPoint, an)){
            currentShape->setPoint(currentPoint, an.toPoint());
        } else {
            currentShape->setPoint(currentPoint, event->pos());
        }
        if (currentShape->basePointsCount() == currentPoint)
        {
            Model::inst().addShape(currentShape);
            currentShape = nullptr;
            repaint();
        } else {
            currentPoint++;
        }
    }
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    lastPoint = event->pos();
    if (currentShape)
    {
        Anchor an;
        AnchorGetter anchorGetter;
        if (anchorGetter.getNearestAnchor(lastPoint, an)){
            currentShape->setPoint(currentPoint, an.toPoint());
        } else {
            currentShape->setPoint(currentPoint, event->pos());
        }
    }
    repaint();
}

void View::startDrawShape(Shape* shape)
{
    if (currentShape){
        delete currentShape;
    }
    currentPoint = 1;
    currentShape = shape;
}

void View::startDrawRect()
{
    startDrawShape(new RectShape());
}

void View::startDrawCenterRect()
{
    startDrawShape(new RectCenterShape());
}

void View::startDrawLine()
{
    startDrawShape(new LineShape());
}

void View::startDrawCenterLine()
{
    startDrawShape(new LineCenterShape());
}

void View::startDrawCircle()
{
    startDrawShape(new CircleShape());
}

void View::startDrawCircle3()
{
    startDrawShape(new Circle3Shape());
}
