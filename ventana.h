#ifndef VENTANA_H
#define VENTANA_H

#include "objeto.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QPrinter>
#include <QDebug>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    Objeto * objeto;
    QString mostrar();
    ~Ventana();

private slots:
    void slot_general();
    void slot_requeridos();
    void slot_requirentes();
    void slot_guardar();
    void slot_mostrar();

    void on_actionGuardar_triggered();

    void on_actionCerrar_triggered();

    void on_actionNuevo_triggered();

    void on_pushButton_clicked();

private:
    Ui::Ventana *ui;
};
#endif // VENTANA_H
