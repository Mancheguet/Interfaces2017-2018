#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QDialog>

#include "ui_calculadora.h"

class Calculadora : public QDialog, public Ui::Calculadora
{
    Q_OBJECT

public:
    Calculadora(QWidget *parent = 0);

private slots:
    void editPantalla1();
    void editPantalla2();
    void editPantalla3();
};

#endif
