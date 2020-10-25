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
    Ventana(Objeto* obj = nullptr, QWidget *parent = nullptr);
    Objeto * obj;

    ~Ventana();

private slots:
    void slot_general();
    void slot_requeridos();
    void slot_requirentes();
    void slot_guardar();

private:
    Objeto * objeto;
    Ui::Ventana *ui;
};
#endif // VENTANA_H
