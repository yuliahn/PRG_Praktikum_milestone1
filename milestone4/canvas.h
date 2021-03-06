#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>

#include "aufgabe2.h"
#include "NeuralNet/neuralnet.h"

using namespace std;

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    vector<vector<double>> setCanvas(int x, int y);
    void setPixel(int i, int j);
    void setPixel(int i, int j, unsigned int value);

    void rowsPixel(double value);
    void columnsPixel(double value);

    unsigned getSizeOfCanvas {this->canvas.size()};

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e) override;
    void createField(QPainter &p);
    void paintField(QPainter &p);

    signals:
    void  environmentChanged(bool ok);
    void TSPends(bool ok);

private slots:
    void on_setButton_clicked();
    void on_clearButton_clicked();

    void on_testData_clicked();

    void on_importDataButton_clicked();

    void on_importLabelsButton_clicked();

    void on_feedImage_clicked();

    void on_trainButton_clicked();

    void on_predictNumberButton_clicked();

    void on_exportWeightsButton_clicked();

    void on_importWeightsButton_clicked();

private:
    Ui::Canvas *ui;
    vector<vector<double>> canvas;
    int xPixel;
    int yPixel;
    vector<vector<vector<unsigned int>>> data;
    vector<vector<unsigned int>> labels;
    NeuralNet net;

};

#endif // CANVAS_H
