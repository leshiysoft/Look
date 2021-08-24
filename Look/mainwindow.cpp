#include "mainwindow.h"
#include "view.h"

#include <QScrollArea>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //QLabel *imageLabel = new QLabel;
    //QImage image("C:/Users/User/Pictures/1.jpg");
    //imageLabel->setPixmap(QPixmap::fromImage(image));

    View* view = new View();

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(view);

    scrollArea->setBackgroundRole(QPalette::Highlight);

    setCentralWidget(scrollArea);


    QMenu* drawmenu = new QMenu("Фигура");
    drawmenu->addAction("Прямоугольник", view, SLOT(startDrawRect()));
    menuBar()->addMenu(drawmenu);
}

MainWindow::~MainWindow()
{
}

