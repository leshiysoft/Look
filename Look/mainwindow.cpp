#include "mainwindow.h"
#include "view.h"

#include <QScrollArea>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    View* view = new View(this);

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(view);

    scrollArea->setBackgroundRole(QPalette::Dark);

    setCentralWidget(scrollArea);

    QMenu* linemenu = new QMenu("Отрезок");
    linemenu->addAction("По двум точкам", view, SLOT(startDrawLine()));
    linemenu->addAction("По центру и точке", view, SLOT(startDrawCenterLine()));
    menuBar()->addMenu(linemenu);

    QMenu* rectmenu = new QMenu("Прямоугольник");
    rectmenu->addAction("По противоположным углам", view, SLOT(startDrawRect()));
    rectmenu->addAction("По центру и углу", view, SLOT(startDrawCenterRect()));
    menuBar()->addMenu(rectmenu);

    QMenu* circlemenu = new QMenu("Окружность");
    circlemenu->addAction("По центру и точке", view, SLOT(startDrawCircle()));
    circlemenu->addAction("По трем точкам", view, SLOT(startDrawCircle3()));
    menuBar()->addMenu(circlemenu);

}

MainWindow::~MainWindow()
{
}

