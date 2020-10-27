#ifndef OBJETO_H
#define OBJETO_H
#include <QDebug>

#include <QObject>

class Objeto : public QObject
{
    Q_OBJECT
public:
    explicit Objeto(QObject *parent = nullptr);
    struct per{
        QString NOMBRE;
        QString N_DNI;
        QString Domicilio_R;
        QString Correo_E;
        QString Celular;
        QString Letrado;
        QString Domicilio_L;
        QString Correo_E_L;
        QString Celular_L;
    };

    //datos Generales
    QString N_Legajo;
    QString N_Acuerdo;
    QString H_Inicio;
    QString H_Cierre;
    QString Fecha;
    QString FechaActual;



    QVector<per>requirentes, requeridos;
    /*
    QString texto_general;
    QString texto_requeridos;
    QString texto_requirentes;
    QString texto_final;
    */

    /**
     *VARIABLES PARA ACTA DE CIERRE
     * II. INFORMACIÓN DE LA MEDIACIÓN
    */
        QString C_Inf_Fecha_Actual;
        QString C_Inf_Legajo_Nro;
        QString C_Inf_Cantidad_Reuniones;
        QString C_Inf_Fecha_Primera_Reunion;
        QString C_Inf_Fecha_Ultima_Reunion;
        QString C_Inf_Resultado_de_a_Mediacion;
        QVector<QString> C_Inf_Rubros_acordados, C_Inf_Rubros_no_acordados;
        QString C_Inf_Monto;
        QString C_Inf_Transcripcion_del_texto_del_acuerdo;
        QString C_Inf_voluntad_de_reconvenir;
        QString C_Inf_Alcance;
    /**
     * HONORARIOS
    */
        QString C_Monto_Abogado_Requirente;
        QString C_Monto_Persona1;
        QString C_Monto_Abogado_Requerido;
        QString C_Monto_Persona2;

    /**
     * TASA Y APORTES
    */
        QString C_Tasa_Monto;
        QString C_Tasa_Persona1;
        QString C_Tasa_Aportes1;
        QString C_Tasa_Persona2;
        QString C_Tasa_Aportes2;
        QString C_Tasa_Persona3;
    /**
     *MULTAS
    */
        QString M_Multa;
        QString M_Domicilio;
        QString M_N_de_expediente;
    /**
     *CONSTANCIAS ADICIONALES*
    */
        QString CA_Verdadero_Falso_1;
        QString CA_Fecha_1;
        QString CA_Verdadero_Falso_2;
        QString CA_Fecha_2;

};

#endif // OBJETO_H
