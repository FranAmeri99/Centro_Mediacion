#ifndef PERSONA_H
#define PERSONA_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class Persona;
}

class Persona : public QWidget
{
    Q_OBJECT

public:
    explicit Persona(bool * tipo = nullptr ,Objeto * obj  = nullptr ,  QWidget *parent = nullptr);
    ~Persona();
    Objeto * obj;
    bool * tipo;
    Objeto::per p1;
    QByteArray * requeridos;
    QByteArray * requirentes;
    QByteArray * inicio;

private slots:
    void on_pbGuardar_clicked();

private:
    Ui::Persona *ui;
};

#endif // PERSONA_H
