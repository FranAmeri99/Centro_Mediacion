#include "persona.h"
#include "ui_persona.h"

Persona::Persona( bool * tipo, Objeto * obj, QWidget * parent ) :
    QWidget( parent ),
    ui( new Ui::Persona )
{
    //si tipo = true entoces es un requerido
    //si tipo = false entoces es  un requirente
    ui->setupUi( this );

    this->obj =  obj;
    this->tipo = tipo;

    if(*tipo){
        this->setWindowTitle("Datos Requeridos");
    }
    else {
        this->setWindowTitle("Datos Requirente");
    }
qDebug()<<*tipo;


}

Persona::~Persona()
{
    delete ui;
}

void Persona::on_pbGuardar_clicked()
{

    p1.NOMBRE = ui->lNombre->text().toUtf8();
    p1.N_DNI= ui->lDNI->text().toUtf8();
    p1.Domicilio_R = ui->lDomicioR->text().toUtf8();
    p1.Correo_E = ui->lCorreo1->text().toUtf8();
    p1.Celular = ui->lCelular1->text().toUtf8();
    p1.Letrado = ui->lLetrado->text().toUtf8();
    p1.Domicilio_L = ui->lDomicilioL->text().toUtf8();
    p1.Correo_E_L = ui->lCorreo2->text().toUtf8();
    p1.Celular_L = ui->lCelular2->text().toUtf8();

    QString NOMBRE = ui->lNombre->text().toUtf8();
    QString N_DNI= ui->lDNI->text().toUtf8();
    QString Domicilio_R = ui->lDomicioR->text().toUtf8();
    QString Correo_E = ui->lCorreo1->text().toUtf8();
    QString Celular = ui->lCelular1->text().toUtf8();
    QString Letrado = ui->lLetrado->text().toUtf8();
    QString Domicilio_L = ui->lDomicilioL->text().toUtf8();
    QString Correo_E_L = ui->lCorreo2->text().toUtf8();
    QString Celular_L = ui->lCelular2->text().toUtf8();

    if(*tipo){

        //obj->requirentes.append(p1); //agrego al QVector No Funciona
        //Agrego al QString de Persona->Requierentes
        obj->requeridos<<p1;
        qDebug()<<*tipo;


    }
    else{


        obj->requirentes<<p1;
        qDebug()<<*tipo;
        qDebug()<<obj->requirentes.size();

//        for (int i = 0; i < obj->requirentes.size();i++) {
//           qDebug()<<"<-------------   "   << i << "---------------------";
//           qDebug()<<"<b>Actor/ requirente  " + obj->requirentes[i].NOMBRE;
//           qDebug()<<"DNI:" + obj->requirentes[i].N_DNI;
//           qDebug()<<"Domicilio real:" + obj->requirentes[i].Domicilio_R;
//           qDebug()<<"Correo electrónico: " + obj->requirentes[i].Correo_E;
//           qDebug()<<"Celular: " + obj->requirentes[i].Celular;
//           qDebug()<<"Letrado: " + obj->requirentes[i].Letrado ;
//           qDebug()<<"Domicilio legal: " + obj->requirentes[i].Domicilio_L;
//           qDebug()<<"Correo electrónico: " + obj->requirentes[i].Correo_E_L;
//           qDebug()<<"Celular:" + obj->requirentes[i].Celular_L ;
//       }


    }
    this->hide();

}
