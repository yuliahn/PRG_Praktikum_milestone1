#include "tspwidget.h"
#include "elasticnet.h"
#include "iterable.h"
#include "iterator.h"

#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include "QTime"

TSPwidget::TSPwidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this)),
    iteration(-1)
{
    //ca1(),
    iterable.setAlpha(1);
    iterable.setBeta(1);
    iterable.setK0(0.1);

    iterator.setIterMax(10000);
    iterator.setEtaZiel(0.005);
    net.setRadius(0.1);
    net.setCVRatio(2.5);

    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(newIteration()));
    string m_masterColor = "#000";
}

TSPwidget::~TSPwidget()
{
}

void TSPwidget::startTSP(const int &number) // Start TSP
{
    iteration = number;

    net.addNodes();



    iterable.setElasticNet(net); // assign the net to the iterable
    iterator.setIterObject(iterable); // assign the iterable to the iterator
    timer->start();


}

void TSPwidget::stopTSP()  //Stop TSP
{
    timer->stop();
}

void TSPwidget::clear() // Clear TSP field
{
    net.clearCities();
    net.clearNodes();

    TSPends(true);
    update();

}


int TSPwidget::interval() // Interval between iterations
{
    return timer->interval();
}

void TSPwidget::setInterval(int msec) // Set interval between iterations
{
    timer->setInterval(msec);
}

void TSPwidget::setAlpha(double value)
{
    iterable.setAlpha(value);
}

void TSPwidget::setBeta(double value)
{
    iterable.setBeta(value);
}

void TSPwidget::setK0(double value)
{
    iterable.setK0(value);
}

void TSPwidget::setMaxIter(int value)
{
    iterator.setIterMax(value);
}

void TSPwidget::setEtaZiel(double value)
{
    iterator.setEtaZiel(value);
}

void TSPwidget::setRadius(double value)
{
    net.setRadius(value);
}
void TSPwidget::setCVRatio(double value)
{
    net.setCVRatio(value);
}


void TSPwidget::newIteration()  // Start the Trading Salesman Problem (TSP) and update nodes positions
{
    if (iteration < 0)
        iteration++;

    double etaN = iterable.apply(iteration);
    //update();

    /*
    if (etaN <= iterator.getEtaZiel() or iteration == iterator.getIterMax()) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
    */


    iteration++;

    // /*
    if (iteration == iterator.getIterMax()) {
        stopTSP();
        TSPends(true);
        QMessageBox::information(this,
                                 tr("TSP finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }
    update();
    //*/
}

void TSPwidget::paintEvent(QPaintEvent * event) {
    QPainter p(this);
    paintGrid(p);
    paintField(p);
    paintFieldNode(p);

}

void TSPwidget::mousePressEvent(QMouseEvent *event) {
    emit environmentChanged(true);
    double k = event->y();
    double j = event->x();
    net.addCity(j/500,k/500);
    cout << "Cities: " << net.getNumOfCities() << endl;
    net.setCentroid();
    net.setNumOfNodes();
    cout << "CV ratio: " << net.getCvRatio() << endl;
    net.addNodes();
    net.preprocess();
    cout << "Number of nodes: " << net.getNumOfNodes()<<endl;
    update();
}

void TSPwidget::mouseMoveEvent(QMouseEvent *event) {
    double k = event->y();
    double j = event->x();

    net.addCity(j/500,k/500);
    net.setNumOfNodes();
    net.setCentroid();
    net.addNodes();
    net.preprocess();
    cout << net.getNumOfNodes()<<endl;
    update();
}

void TSPwidget::paintGrid(QPainter &p) {
    int size = 500;
    QRect borders(0, 0, size - 1, size - 1); // borders of the universe
    QColor gridColor = "#000"; // color of the grid
    gridColor.setAlpha(20); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double) size / 50 ; // width of the widget / number of cells at one row
    for (double k = cellWidth; k <= size; k += cellWidth)
        p.drawLine(k, 0, k, size);
    double cellHeight = (double) size / 50; // height of the widget / number of cells at one row
    for (double k = cellHeight; k <= size; k += cellHeight)
        p.drawLine(0, k, size, k);
    p.drawRect(borders);
}

void TSPwidget::paintField(QPainter &p) {
    double cellWidth = 500 / 50;
    double cellHeight = 500 / 50;
    for(int x = 0; x < net.getNumOfCities(); x++){
        double y = net.getCoordX(x) * 500 / cellWidth;
        double z = net.getCoordY(x) * 500 / cellHeight;
        qreal left = (qreal)(cellWidth * y - cellWidth); // margin from left
        qreal top = (qreal)(cellHeight * z - cellHeight); // margin from top
        QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(r, QBrush(Qt::red));
    }
}

void TSPwidget::paintFieldNode(QPainter &p) {
    double cellWidth = 500 / 50;
    double cellHeight = 500 / 50;

    for(int a = 0; a < net.getNumOfNodes(); a++){
        double b = net.getNodeCoordX(a) * 500 / cellWidth;
        double c = net.getNodeCoordY(a) * 500 / cellHeight;
        cout << "Node coords: " << b << "," << c << endl;
        qreal left = (qreal)(cellWidth * b - cellWidth); // margin from left
        qreal top = (qreal)(cellHeight * c - cellHeight); // margin from top
        QRectF hi(left, top, (qreal) cellWidth, (qreal) cellHeight);
        p.fillRect(hi, QBrush(Qt::green));
    }
}
