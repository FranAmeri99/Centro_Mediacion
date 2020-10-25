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
        QByteArray *NOMBRE;
        QByteArray *N_DNI;
        QByteArray *Domicilio_R;
        QByteArray *Correo_E;
        QByteArray *Celular;
        QByteArray *Letrado;
        QByteArray *Domicilio_L;
        QByteArray *Correo_E_L;
        QByteArray *Celular_L;
    };

    QByteArray *N_Legajo;
    QByteArray *N_Acuerdo;
    QByteArray *H_Inicio;
    QByteArray *H_Cierre;
    QByteArray *Fecha;

    void set_legajo(QByteArray * Legajo){N_Legajo = Legajo;};
    void set_Acuerdo(QByteArray * Acuerdo){N_Acuerdo = Acuerdo;};
    void set_HInicio(QByteArray * HInicio){H_Inicio= HInicio;};
    void set_HCierre(QByteArray * HCierre){H_Cierre= HCierre;};
    void set_Fecha(QByteArray * fe){Fecha= fe;};

    QVector<per>requirentes, requeridos;

    QByteArray *texto_general;
    QByteArray *texto_requeridos = new QByteArray;
    QByteArray *texto_requirentes = new QByteArray;

    QByteArray *texto_final = new QByteArray();



signals:

};

#endif // OBJETO_H
