#ifndef ACTACIERRE_H
#define ACTACIERRE_H

#include <QWidget>
#include "objeto.h"
#include "constancias.h"
#include "multa.h"
#include "tasa.h"
#include "honorario.h"

namespace Ui {
class ActaCierre;
}

class ActaCierre : public QWidget
{
    Q_OBJECT

public:
    explicit ActaCierre(Objeto * obj  = nullptr, QWidget *parent = nullptr);
    ~ActaCierre();
    Objeto *obj;

private slots:
    void on_pbInformacion_clicked();

    void on_pbHonorarios_clicked();

    void on_pbMulta_clicked();

    void on_pbConstancia_clicked();

    void on_pbGuardar_clicked();

    void on_pbTasa_clicked();

private:
    Ui::ActaCierre *ui;
};

#endif // ACTACIERRE_H
