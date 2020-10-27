#include "actacierre.h"
#include "informacioncierre.h"
#include "ui_actacierre.h"

ActaCierre::ActaCierre(Objeto * obj , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActaCierre)
{
    ui->setupUi(this);
    this->obj=obj;

}

ActaCierre::~ActaCierre()
{
    delete ui;
}

void ActaCierre::on_pbInformacion_clicked()
{
    InformacionCierre * informacion = new InformacionCierre(obj);
    informacion->show();
}

void ActaCierre::on_pbHonorarios_clicked()
{
    Honorario * honorario = new Honorario(obj);
    honorario->show();

}

void ActaCierre::on_pbMulta_clicked()
{
    Multa * multa = new Multa(obj);
    multa->show();
}

void ActaCierre::on_pbConstancia_clicked()
{
    Constancias * constancias = new Constancias(obj);
    constancias->show();
}

void ActaCierre::on_pbGuardar_clicked()
{
    this->hide();
}

void ActaCierre::on_pbTasa_clicked()
{
    Tasa * tasa = new Tasa(obj);
    tasa->show();
}
