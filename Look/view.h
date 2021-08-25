#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <shape.h>
#include "modelvisitor.h"


class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void startDrawShape(Shape* shape);

private:
    Shape* currentShape;
    int currentPoint;
    QPoint lastPoint;

signals:

public slots:
    void startDrawRect();
    void startDrawCenterRect();
    void startDrawLine();
    void startDrawCenterLine();
    void startDrawCircle();
    void startDrawCircle3();

};

class ShapeDrawer : public ModelVisitor
{
public:
    ShapeDrawer(QPainter* _painter)
    {
        painter = _painter;
    }
    void visit(QVector<Shape*> shapes){
        foreach(Shape* shape, shapes){
            shape->draw(painter);
        }
    }
private:
    QPainter* painter;
};

#endif // VIEW_H
