#include "informacioncierre.h"
#include "ui_informacioncierre.h"

InformacionCierre::InformacionCierre(Objeto * obj,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InformacionCierre)
{
    ui->setupUi(this);
    this->obj=  obj;
    this->setMaximumSize(300,300);
}

InformacionCierre::~InformacionCierre()
{
    delete ui;
}

void InformacionCierre::on_pbGuardar_clicked()
{
    /*

     */

    obj->C_Inf_Cantidad_Reuniones = ui->lCantidad->text();
    obj->C_Inf_Fecha_Primera_Reunion = ui->dPrimera->text();
    obj->C_Inf_Fecha_Ultima_Reunion = ui->dUltima->text();
    obj->C_Inf_Resultado_de_a_Mediacion = ui->comboBox->currentText();
    obj->C_Inf_Monto = ui->lMonto->text();
   //obj->C_Inf_Transcripcion_del_texto_del_acuerdo = ui->
    obj->C_Inf_voluntad_de_reconvenir = ui->comboBox2->currentText();
   // obj->C_Inf_Alcance = ui->
    this->hide();
}
