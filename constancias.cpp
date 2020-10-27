#include "constancias.h"
#include "ui_constancias.h"

Constancias::Constancias(Objeto * obj ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Constancias)
{
    ui->setupUi(this);
    this->obj=obj;

}

Constancias::~Constancias()
{
    delete ui;
}

void Constancias::on_pbGuardar_clicked()
{
    this->hide();
}
