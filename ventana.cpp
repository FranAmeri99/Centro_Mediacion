#include "ventana.h"
#include "general.h"
#include "persona.h"
#include "ui_ventana.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

Ventana::Ventana(Objeto *obj, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ventana)
{

    this->obj=obj;
    ui->setupUi(this);
    connect(ui->pbGeneral, SIGNAL(clicked()),this, SLOT(slot_general()));
    connect(ui->pbGuardar, SIGNAL(clicked()),this, SLOT(slot_guardar()));
    connect(ui->pbRequerido, SIGNAL(clicked()),this, SLOT(slot_requeridos()));
    connect(ui->pbRequirente, SIGNAL(clicked()),this, SLOT(slot_requirentes()));
    obj->texto_final->append("<div style=\"position:absolute;left:72.02px;top:456.95px\" class=\"cls_002\"><span class=\"cls_002\">OBSERVACIONES</span><span class=\"cls_003\">:</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:478.67px\" class=\"cls_004\"><span class=\"cls_004\">Se deja constancia que el/la/los requirentes/actor/es Sres/as._______________________; y</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:492.47px\" class=\"cls_004\"><span class=\"cls_004\">el/la/los requeridos/demandado/s__________________________________________y los/as</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:506.27px\" class=\"cls_004\"><span class=\"cls_004\">abogados/as _________________________han sido debidamente informados del principio de</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:520.07px\" class=\"cls_004\"><span class=\"cls_004\">confidencialidad que rige el proceso de mediación (arts.</span></div>"
                                "<div style=\"position:absolute;left:366.95px;top:520.07px\" class=\"cls_004\"><span class=\"cls_004\">3 y 4 de la ley 10.543 y Dec.</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:533.90px\" class=\"cls_004\"><span class=\"cls_004\">Reglamentario 1705/18, arts. 4 y 5 ley 8858 y art.156 del Código Penal) y que  leído el convenio</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:547.70px\" class=\"cls_004\"><span class=\"cls_004\">de confidencialidad en la audiencia celebrada el día</span></div>"
                                "<div style=\"position:absolute;left:351.88px;top:547.70px\" class=\"cls_004\"><span class=\"cls_004\">_____________________, bajo la</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:561.50px\" class=\"cls_004\"><span class=\"cls_004\">modalidad de mediación virtual, han manifestando respetar,  prestando conformidad.</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:583.34px\" class=\"cls_004\"><span class=\"cls_004\">Asimismo, que los mediadores intervinientes, han realizado  captura o print de pantalla de la</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:597.14px\" class=\"cls_004\"><span class=\"cls_004\">reunión realizada, con el único fin de acreditar la identidad y  asistencia de las partes y sus</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:610.94px\" class=\"cls_004\"><span class=\"cls_004\">letrados.</span></div>"
                                "<div style=\"position:absolute;left:90.02px;top:632.90px\" class=\"cls_005\"><span class=\"cls_005\">-</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:632.90px\" class=\"cls_004\"><span class=\"cls_004\">Las </span><span class=\"cls_003\">partes </span><span class=\"cls_004\">se comprometen </span><span class=\"cls_003\">a remitir el convenio de confidencialidad,  ratificar tal</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:646.70px\" class=\"cls_003\"><span class=\"cls_003\">acto,  como así también la asistencia a la audiencia</span><span class=\"cls_004\"> a través de correo electrónico</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:660.50px\" class=\"cls_004\"><span class=\"cls_004\">desde su casilla personal, asumiendo dicho acto el valor de  Declaración Jurada.</span></div>"
                                "<div style=\"position:absolute;left:90.02px;top:674.54px\" class=\"cls_005\"><span class=\"cls_005\">-</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:674.54px\" class=\"cls_004\"><span class=\"cls_004\">Los/as </span><span class=\"cls_003\"> letrados  intervinientes  y  los/as  mediadores</span><span class=\"cls_004\">  también  efectuarán  dicha</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:688.34px\" class=\"cls_004\"><span class=\"cls_004\">ratificación,  a través de una presentación en la plataforma electrónica (arts. 2, 3 y 11</span></div>"
                                "<div style=\"position:absolute;left:108.02px;top:702.16px\" class=\"cls_004\"><span class=\"cls_004\">Reglamento de EE.).</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:724.00px\" class=\"cls_004\"><span class=\"cls_004\">Asimismo todas las partes manifiestan que se encuentran notificadas del nuevo día y hora de</span></div>"
                                "<div style=\"position:absolute;left:72.02px;top:737.80px\" class=\"cls_004\"><span class=\"cls_004\">audiencia para el________________________ quedando debidamente notificadas en este acto.</span></div>"
                                "</div>"
                                "<div style=\"position:absolute;left:50%;margin-left:-297px;top:851px;width:595px;height:841px;border-style:outset;overflow:hidden\">"
                                "<div style=\"position:absolute;left:0px;top:0px\></div>"
                                "</div>"
                                "</body>"
                                "</html>");

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
    qDebug()<<"Guardar";
    QByteArray * html = new QByteArray;
    //html->append(obj->texto_general);
    //html->append(obj->texto_requeridos);
    //html->append(obj->texto_requirentes);

    html->append("<div style=\"position:absolute;left:0px;top:0px\"></div>"
                        "</div>"
                        "</body>"
                        "</html>");
    //Los datos generales solo se cargan una vez, si se vuele a abrir la ventana debo actualizar los datos
    //Los datos requirentes y requeridos son varios y se deben agregar todos
    //Al final agrego lineas necesiras para terminal el html

    ui->text->setHtml(*html);
    //para convertir de Html a pdf
    QTextDocument document;
    document.setHtml(*html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(QFileDialog::getSaveFileName(this, "Guardar")+ ".pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);
    qDebug()<<"listo";
}




