#ifndef CONSTANCIAS_H
#define CONSTANCIAS_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class Constancias;
}

class Constancias : public QWidget
{
    Q_OBJECT

public:
    explicit Constancias(Objeto * obj  = nullptr  , QWidget *parent = nullptr);
    ~Constancias();
    Objeto *obj;

private slots:
    void on_pbGuardar_clicked();

private:
    Ui::Constancias *ui;
};

#endif // CONSTANCIAS_H
