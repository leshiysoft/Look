#include "view.h"
#include "rectshape.h"
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
    qDebug() << "painted";
}

void View::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Press: (" << event->x() << ", " << event->y() << ")";
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
    qDebug() << "Move: (" << event->x() << ", " << event->y() << ")";
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

void View::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Release: (" << event->x() << ", " << event->y() << ")";
}

void View::startDrawRect()
{
    if (currentShape){
        delete currentShape;
    }
    currentPoint = 1;
    qDebug() << "start draw rect";
    currentShape = new RectShape();
}
