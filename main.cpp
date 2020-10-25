#include "ventana.h"
#include "general.h"

#include "objeto.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Objeto * objeto = new Objeto;

    Ventana * w = new Ventana(objeto);
    w->show();
    return a.exec();
}
