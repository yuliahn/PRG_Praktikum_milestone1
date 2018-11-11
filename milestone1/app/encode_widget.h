#ifndef ENCODE_WIDGET_H
#define ENCODE_WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <QFileDialog>
#include <QGraphicsScene>

namespace Ui {
class encode_widget;
}

class encode_widget : public QWidget
{
    Q_OBJECT

public:
    explicit encode_widget(QWidget *parent = nullptr);
    ~encode_widget();

private slots:
    void on_import_data_clicked();

    void on_generate_key_clicked();

    void on_encode_clicked();

    void on_export_result_clicked();

    void on_export_key_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

private:
    Ui::encode_widget *ui;
};

#endif // ENCODE_WIDGET_H
