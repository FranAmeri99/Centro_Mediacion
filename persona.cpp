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

    if(tipo){
        this->setWindowTitle("Datos Requeridos");
    }
    else {
        this->setWindowTitle("Datos Requirente");
    }

    requeridos = new QByteArray;
    requirentes = new QByteArray;

}

Persona::~Persona()
{
    delete ui;
}

void Persona::on_pbGuardar_clicked()
{
/*  hacer q funcione lo comentado ?
    *p1.NOMBRE = ui->lNombre->text().toUtf8();
    *p1.N_DNI= ui->lDNI->text().toUtf8();
    *p1.Domicilio_R = ui->lDomicioR->text().toUtf8();
    *p1.Correo_E = ui->lCorreo1->text().toUtf8();
    *p1.Celular = ui->lCelular1->text().toUtf8();
    *p1.Letrado = ui->lLetrado->text().toUtf8();
    *p1.Domicilio_L = ui->lDomicilioL->text().toUtf8();
    *p1.Correo_E_L = ui->lCorreo2->text().toUtf8();
    *p1.Celular_L = ui->lCelular2->text().toUtf8();
*/

    QByteArray NOMBRE = ui->lNombre->text().toUtf8();
    QByteArray N_DNI= ui->lDNI->text().toUtf8();
    QByteArray Domicilio_R = ui->lDomicioR->text().toUtf8();
    QByteArray Correo_E = ui->lCorreo1->text().toUtf8();
    QByteArray Celular = ui->lCelular1->text().toUtf8();
    QByteArray Letrado = ui->lLetrado->text().toUtf8();
    QByteArray Domicilio_L = ui->lDomicilioL->text().toUtf8();
    QByteArray Correo_E_L = ui->lCorreo2->text().toUtf8();
    QByteArray Celular_L = ui->lCelular2->text().toUtf8();

    if(tipo){

        //obj->requirentes.append(p1); //agrego al QVector No Funciona
        //Agrego al QByteArray de Persona->Requierentes

        requirentes->append("<div style=\"position:absolute;left:72.02px;top:180.90px\" class=\"cls_003\"><span class=\"cls_003\">Actor/ requirente:" + NOMBRE + "</span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:194.70px\" class=\"cls_004\"><span class=\"cls_004\">DNI: " + N_DNI + "</span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:208.50px\" class=\"cls_004\"><span class=\"cls_004\">Domicilio real: " + Domicilio_R + "</span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:222.33px\" class=\"cls_004\"><span class=\"cls_004\">Correo electrónico: " + Correo_E + " </span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:236.13px\" class=\"cls_004\"><span class=\"cls_004\">Celular  " + Celular + " </span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:249.93px\" class=\"cls_004\"><span class=\"cls_004\">Letrado: " + Letrado + " </span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:263.73px\" class=\"cls_004\"><span class=\"cls_004\">Domicilio legal: " + Domicilio_L + " </span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:277.53px\" class=\"cls_004\"><span class=\"cls_004\">Correo electrónico: " + Correo_E_L + " </span></div>\n");
        requirentes->append("<div style=\"position:absolute;left:72.02px;top:291.33px\" class=\"cls_004\"><span class=\"cls_004\">Celular  " + Celular_L + " </span></div>\n");


    }
    else{
        //obj->requeridos.append(p1);//agrego al QVector
        //Agrego al QByteArray de Persona->Requeridos
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:180.90px\" class=\"cls_003\"><span class=\"cls_003\">Demandada/ requerido:" + *p1.NOMBRE + "</span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:194.70px\" class=\"cls_004\"><span class=\"cls_004\">DNI: " + *p1.N_DNI + "</span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:208.50px\" class=\"cls_004\"><span class=\"cls_004\">Domicilio real: " + *p1.Domicilio_R + "</span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:222.33px\" class=\"cls_004\"><span class=\"cls_004\">Correo electrónico: " + *p1.Correo_E + " </span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:236.13px\" class=\"cls_004\"><span class=\"cls_004\">Celular  " + *p1.Celular + " </span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:249.93px\" class=\"cls_004\"><span class=\"cls_004\">Letrado: " + *p1.Letrado + " </span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:263.73px\" class=\"cls_004\"><span class=\"cls_004\">Domicilio legal: " + *p1.Domicilio_L + " </span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:277.53px\" class=\"cls_004\"><span class=\"cls_004\">Correo electrónico: " + *p1.Correo_E_L + " </span></div>\n");
        requeridos->append("<div style=\"position:absolute;left:72.02px;top:291.33px\" class=\"cls_004\"><span class=\"cls_004\">Celular  " + *p1.Celular_L + " </span></div>\n");
        qDebug()<<*requeridos;
    }
    this->hide();

}
