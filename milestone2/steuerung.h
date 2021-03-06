//author: Ischa Tahir (5935200)

#ifndef STEUERUNG_H
#define STEUERUNG_H

#include <QWidget>
#include "tspwidget.h"

namespace Ui {
class Steuerung;
}

class Steuerung : public QWidget
{
    Q_OBJECT

public:
    explicit Steuerung(QWidget *parent = nullptr);

    ~Steuerung();

private slots:
    void on_label_linkActivated(const QString &link);

private:
    Ui::Steuerung *ui;
    TSPwidget *tsp;
};

#endif // STEUERUNG_H
