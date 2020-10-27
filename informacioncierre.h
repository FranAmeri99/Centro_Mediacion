#ifndef INFORMACIONCIERRE_H
#define INFORMACIONCIERRE_H

#include <QWidget>
#include "objeto.h"



namespace Ui {
class InformacionCierre;
}

class InformacionCierre : public QWidget
{
    Q_OBJECT

public:
    explicit InformacionCierre(Objeto * obj  = nullptr, QWidget *parent = nullptr);
    ~InformacionCierre();
    Objeto *obj;


private slots:
    void on_pbGuardar_clicked();

private:
    Ui::InformacionCierre *ui;
};

#endif // INFORMACIONCIERRE_H
