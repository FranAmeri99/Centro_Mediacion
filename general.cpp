#include "general.h"
#include "ui_general.h"
#include <QDebug>

General::General(Objeto *obj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::General)
{
    this->obj=obj;

    ui->setupUi(this);
    //encabezaso no se modidifica nunca;

}


General::~General()
{
    delete ui;
}

void General::on_Guardar_clicked()
{
    obj->FechaActual =ui->tFechaActual->text().toUtf8();
    obj->N_Legajo = ui->lLegajoN->text().toUtf8();
    obj->N_Acuerdo= ui->lNumeroA->text().toUtf8();
    obj->H_Inicio =  ui->tNueva->text().toUtf8();
    obj->H_Cierre=  ui->tFin->text().toUtf8();
    obj->Fecha=  ui->tFecha->text().toUtf8();

    this->hide();

}
