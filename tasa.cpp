#include "tasa.h"
#include "ui_tasa.h"

Tasa::Tasa(Objeto * obj ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tasa)
{
    ui->setupUi(this);
    this->obj=obj;
    this->setMaximumSize(700,100);

}

Tasa::~Tasa()
{
    delete ui;
}

void Tasa::on_pbGuardar_clicked()
{
    this->hide();
}
