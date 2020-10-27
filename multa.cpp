#include "multa.h"
#include "ui_multa.h"

Multa::Multa(Objeto * obj , QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Multa)
{
    ui->setupUi(this);
    this->obj=obj;
    this->setMaximumSize(700,100);

}

Multa::~Multa()
{
    delete ui;
}

void Multa::on_pbGuardar_clicked()
{
    this->hide();
}
