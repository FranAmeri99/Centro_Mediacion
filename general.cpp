#include "general.h"
#include "ui_general.h"
#include <QDebug>

General::General(Objeto *obj, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::General)
{
    this->obj=obj;

    ui->setupUi(this);
    inicio = new QByteArray;
    //encabezaso no se modidifica nunca;
    inicio->append("<html>\n"
                   "<head><meta http-equiv=Content-Type content=\"text/html; charset=UTF-8\">\n"
                   "<style type=\"text/css\">\n"
                   "<!--\n"
                   "span.cls_002{font-family:Times,serif;font-size:9.5px;color:rgb(0,0,0);font-weight:bold;font-style:normal;text-decoration: none}\n"
                   "div.cls_002{font-family:Times,serif;font-size:9.5px;color:rgb(0,0,0);font-weight:bold;font-style:normal;text-decoration: none}\n"
                   "span.cls_003{font-family:Times,serif;font-size:12.1px;color:rgb(0,0,0);font-weight:bold;font-style:normal;text-decoration: none}\n"
                   "div.cls_003{font-family:Times,serif;font-size:12.1px;color:rgb(0,0,0);font-weight:bold;font-style:normal;text-decoration: none}\n"
                   "span.cls_004{font-family:Times,serif;font-size:12.1px;color:rgb(0,0,0);font-weight:normal;font-style:normal;text-decoration: none}\n"
                   "div.cls_004{font-family:Times,serif;font-size:12.1px;color:rgb(0,0,0);font-weight:normal;font-style:normal;text-decoration: none}\n"
                   "span.cls_005{font-family:\"Calibri\",serif;font-size:12.1px;color:rgb(0,0,0);font-weight:normal;font-style:normal;text-decoration: none}\n"
                   "div.cls_005{font-family:\"Calibri\",serif;font-size:12.1px;color:rgb(0,0,0);font-weight:normal;font-style:normal;text-decoration: none}\n"
                               "-->\n"
                   "</style>\n"
                   "<script type=\"text/javascript\" src=\"f3bd14f4-15c5-11eb-8b25-0cc47a792c0a_id_f3bd14f4-15c5-11eb-8b25-0cc47a792c0a_files/wz_jsgraphics.js\"></script>\n"
                   "</head>\n"
                   "<body>\n"
                   "<div style=\"position:absolute;left:50%;margin-left:-297px;top:0px;width:595px;height:841px;border-style:outset;overflow:hidden\">"
                   "<div style=\"position:absolute;left:0px;top:0px\">\n"
                   "</div>\n"
                   "<div style=\"position:absolute;left:72.02px;top:70.50px\" class=\"cls_002\"><span class=\"cls_002\">FORMULARIO DE ACREDITACIÓN Y</span><span class=\"cls_003\">/</span><span class=\"cls_002\">O FIJACIÓN DE NUEVO DÍA Y HORA DE REUNIÓN BAJO</span></div>\n"
                   "<div style=\"position:absolute;left:72.02px;top:84.30px\" class=\"cls_002\"><span class=\"cls_002\">MODALIDAD VIRTUAL</span><span class=\"cls_003\">.</span></div>\n"
                   );
}


General::~General()
{
    delete ui;
}

void General::on_Guardar_clicked()
{
    QByteArray legajo = ui->lLegajoN->text().toUtf8();
    QByteArray * acuerdo= new QByteArray(ui->lNumeroA->text().toUtf8());
    QByteArray * i =  new QByteArray(ui->tNueva->text().toUtf8());
    QByteArray * fi =  new QByteArray(ui->tFin->text().toUtf8());
    QByteArray * fe =  new QByteArray(ui->tFecha->text().toUtf8());

    inicio->append("<div style=\"position:absolute;left:72.02px;top:111.90px\" class=\"cls_004\"><span class=\"cls_004\">Legajo N°  Autos  “"+   legajo + " C/  ……………….”</span></div>\n");
    inicio->append("<div style=\"position:absolute;left:72.02px;top:125.70px\" class=\"cls_004\"><span class=\"cls_004\">Acuerdo Reglamentario N° " + *acuerdo +"</span></div>\n");
    inicio->append("<div style=\"position:absolute;left:72.02px;top:139.50px\" class=\"cls_004\"><span class=\"cls_004\">Hora de inicio: "+ *i +" </span></div>\n");
    inicio->append("<div style=\"position:absolute;left:72.02px;top:153.30px\" class=\"cls_004\"><span class=\"cls_004\">Hora de finalización: " + *fi+"</span></div>\n");
    inicio->append("<div style=\"position:absolute;left:72.02px;top:167.10px\" class=\"cls_003\"><span class=\"cls_003\">Nuevo reunión, fecha  "+ *fe+ "</span></div>\n");
    //qDebug()<<*inicio;
    this->hide();

}
