#ifndef TASA_H
#define TASA_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class Tasa;
}

class Tasa : public QWidget
{
    Q_OBJECT

public:
    explicit Tasa(Objeto * obj  = nullptr  ,QWidget *parent = nullptr);
    ~Tasa();
    Objeto *obj;

private slots:
    void on_pbGuardar_clicked();

private:
    Ui::Tasa *ui;
};

#endif // TASA_H
