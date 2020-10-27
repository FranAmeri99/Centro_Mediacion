#include "ventana.h"
#include "general.h"
#include "persona.h"
#include "ui_ventana.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QPainter>
#include <QTimer>
#include "actacierre.h"

Ventana::Ventana( QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ventana)
{
    objeto = new Objeto();

    ui->setupUi(this);
    connect(ui->pbGeneral, SIGNAL(clicked()),this, SLOT(slot_general()));
    connect(ui->pbGuardar, SIGNAL(clicked()),this, SLOT(slot_guardar()));
    connect(ui->pbRequerido, SIGNAL(clicked()),this, SLOT(slot_requeridos()));
    connect(ui->pbRequirente, SIGNAL(clicked()),this, SLOT(slot_requirentes()));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_mostrar()));
    timer->start(1000);
    this->setMinimumSize(700,300);
}



Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_general()
{
    General * general = new General(objeto);
    general->show();
}

void Ventana::slot_requeridos()
{
    bool * tipo = new bool(true);
    Persona * persona = new Persona(tipo,objeto);
    persona->show();
}

void Ventana::slot_requirentes()
{
    bool * tipo = new bool(false);
    Persona * persona = new Persona(tipo,objeto);
    persona->show();
}

void Ventana::slot_guardar()
{
    QString nombre = QFileDialog::getSaveFileName(this,tr("Guardar"), "../", tr("PDF Files (*.pdf)"));

    QString html = mostrar ();
            ui->text->setHtml(html);
            QTextDocument document;
            document.setHtml(html);

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);

            printer.setOutputFileName(nombre + ".pdf");
            printer.setPageMargins(QMarginsF(15, 15, 15, 15));

            document.print(&printer);
            qDebug()<<"listo";
}

void Ventana::slot_mostrar()
{
    ui->text->setHtml(mostrar());
}

QString Ventana::mostrar()
{
    ui->text->clear();
    QString html ="<style>"
                  "#identified  {background-color: black;"
                  "color: white}"
                  "</style>"
                  "<body><b>FORMULARIO DE ACREDITACIÓN Y/O FIJACIÓN DE NUEVO DÍA Y HORA DE REUNIÓN BAJO MODALIDAD VIRTUAL. </b>"
                 "<p> Legajo N°  Autos  “";
                 html.push_back(objeto->N_Legajo+"<br>");

                 html.push_back("Acuerdo Reglamentario N°: "+ objeto->N_Acuerdo + ", Hora de inicio: "+ objeto->H_Inicio +
                 ", Hora de finalización: " + objeto->H_Cierre + "<br>"
                 "<b>Nuevo reunión, fecha " + objeto->Fecha + " hs </b><br>");
                 QString NombreRequeridos;
                 QString NombreRequirentes;
                 QString NombreAbogados;
                qDebug()<<objeto->requirentes.size();
                if(objeto->requirentes.count()>0){
                    for (int i = 0; i < objeto->requirentes.size();i++) {
                       qDebug()<<"valor i : "<<i;
                       html.push_back("<br><b>Actor/ requirente  " + objeto->requirentes[i].NOMBRE + " </b><br>"
                       "DNI/CUIL:" + objeto->requirentes[i].N_DNI + "<br>"
                       "Domicilio real:" + objeto->requirentes[i].Domicilio_R + "<br>"
                       "Correo electrónico: " + objeto->requirentes[i].Correo_E+ "<br>"
                       "Celular: " + objeto->requirentes[i].Celular+ "<br>"
                       "Letrado: " + objeto->requirentes[i].Letrado + "<br>"
                       "Domicilio legal: " + objeto->requirentes[i].Domicilio_L + "<br>"
                       "Correo electrónico: " + objeto->requirentes[i].Correo_E_L + "<br>"
                       "Celular: " + objeto->requirentes[i].Celular_L + "<br>");
                       NombreRequeridos.append(objeto->requirentes[i].NOMBRE );
                       NombreAbogados.append(objeto->requirentes[i].Letrado);

                       if(i==objeto->requirentes.size()){
                           NombreRequeridos.append(", ");
                       }

                   }

                }
                if(objeto->requeridos.count()>0){
                     for (int i = 0; i < objeto->requeridos.size();i++) {
                        html.push_back("<b>Demandada/ requerida  " + objeto->requeridos[i].NOMBRE + " </b><br>"
                        "DNI (si es persona jurídica corresponde consignar el del Representante Legal):" + objeto->requeridos[i].N_DNI + "<br>"
                        "Domicilio real:" + objeto->requeridos[i].Domicilio_R + "<br>"
                        "Correo electrónico: " + objeto->requeridos[i].Correo_E+ "<br>"
                        "Celular: " + objeto->requeridos[i].Celular+ "<br>"
                        "Letrado: " + objeto->requeridos[i].Letrado + "<br>"
                        "Domicilio legal: " + objeto->requeridos[i].Domicilio_L + "<br>"
                        "Correo electrónico: " + objeto->requeridos[i].Correo_E_L + "<br>"
                        "Celular:" + objeto->requeridos[i].Celular_L + "<br><br>");
                        NombreRequirentes.append(objeto->requeridos[i].NOMBRE+" " );
                        NombreAbogados.append( objeto->requirentes[i].Letrado+" " );
                        if(i==objeto->requeridos.size()){
                            NombreRequirentes.append(", ");
                            NombreAbogados.append(",");
                        }
                    }
                }

                html.push_back(
                   "<p background-color: coral ><b>OBSERVACIONES:</b><br>"
                   " Se deja constancia que el/la/los requirentes/actor/es Sres./as. " + NombreRequeridos  + "; y el/la/los requeridos demandados " + NombreRequirentes + "y los/as abogados/as " + NombreAbogados + " "
                   "han sido debidamente informados del principio de confidencialidad  que rige el proceso de mediación (arts.  3 y 4 de la ley 10.543 y Dec. Reglamentario 1705/18, arts. 4 y 5"
                   " ley 8858 y art.156 del Código Penal) y que leído el convenio de confidencialidad en la audiencia celebrada el día " + objeto->Fecha + ", bajo la modalidad de mediación"
                   " virtual, han manifestado respetar, prestando conformidad. "
                   "Asimismo, que los mediadores intervinientes, han realizado captura o print de pantalla de la reunión realizada, con el único fin \"de acreditar la identidad y asistencia de "
                   "las partes y sus letrados.</p>"
                   "<ul><li>Las <b>partes </b> se comprometen <b>a remitir el convenio de confidencialidad, ratificar tal acto,  como así también la \"asistencia a la audiencia </b> a través de "
                   "correo electrónico desde su casilla personal, asumiendo dicho acto el valor de " "Declaración Jurada.\"</li>"
                   "<li>Los/as <b> letrados intervinientes y los/as mediadores </b>"
                   " también efectuarán dicha ratificación, a través de una " "presentación en la plataforma electrónica (arts. 2, "
                   "3 y 11 Reglamento de EE.).</li></ul>  "
                   "<p>Asimismo todas las partes manifiestan que se encuentran notificadas del nuevo día y hora de audiencia para el " +  objeto->FechaActual +" quedando debidamente notificadas en este acto.</p></body>");
            return html;
}

void Ventana::on_actionGuardar_triggered()
{
    slot_guardar();
}

void Ventana::on_actionCerrar_triggered()
{
    close();
}

void Ventana::on_actionNuevo_triggered()
{
    objeto->N_Legajo="";
    objeto->N_Acuerdo="";
    objeto->H_Inicio="";
    objeto->H_Cierre="";
    objeto->Fecha="";
    objeto->FechaActual="";

    objeto->requirentes.clear();
    objeto->requeridos.clear();
}

void Ventana::on_pushButton_clicked()
{
    ActaCierre * actacierre = new ActaCierre(objeto);
    actacierre->show();

}
