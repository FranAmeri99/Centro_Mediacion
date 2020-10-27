#include "honorario.h"
#include "ui_honorario.h"

Honorario::Honorario(Objeto * obj ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Honorario)
{
    ui->setupUi(this);
    this->obj=obj;

}

Honorario::~Honorario()
{
    delete ui;
}

void Honorario::on_pushButton_clicked()
{
    this->hide();
}
