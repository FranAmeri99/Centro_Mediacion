#ifndef GENERAL_H
#define GENERAL_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class General;
}

class General : public QWidget
{
    Q_OBJECT

public:
    explicit General(Objeto * obj  = nullptr  ,QWidget *parent = nullptr);
    Objeto * obj;
    ~General();
    QByteArray * inicio;
private slots:
    void on_Guardar_clicked();

private:
    Ui::General *ui;
};

#endif // GENERAL_H
