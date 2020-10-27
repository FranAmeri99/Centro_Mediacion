#include "ventana.h"
#include "general.h"

#include "objeto.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Ventana * w = new Ventana();
    w->show();
    return a.exec();
}
