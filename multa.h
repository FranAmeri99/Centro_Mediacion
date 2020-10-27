#ifndef MULTA_H
#define MULTA_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class Multa;
}

class Multa : public QWidget
{
    Q_OBJECT

public:
    explicit Multa(Objeto * obj  = nullptr  ,QWidget *parent = nullptr);
    ~Multa();
    Objeto *obj;

private slots:
    void on_pbGuardar_clicked();

private:
    Ui::Multa *ui;
};

#endif // MULTA_H
