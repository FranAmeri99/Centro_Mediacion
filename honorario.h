#ifndef HONORARIO_H
#define HONORARIO_H

#include <QWidget>
#include "objeto.h"

namespace Ui {
class Honorario;
}

class Honorario : public QWidget
{
    Q_OBJECT

public:
    explicit Honorario(Objeto * obj  = nullptr  ,QWidget *parent = nullptr);
    ~Honorario();
    Objeto *obj;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Honorario *ui;
};

#endif // HONORARIO_H
