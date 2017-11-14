#include <QtGui>
#include <QTextEdit>

#include "calculadora.h"

Calculadora::Calculadora(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    //connectar los botones para que salgan los numeros :
    connect(btn1, SIGNAL(clicked()), this, SLOT(editPantalla1()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(editPantalla2()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(editPantalla3()));

}

//EI BOBO , VAS PER LA PART DE CONTINUAR EL CPP , H DE CALCULADORA I DESPRES IMPLEMENTAL EL UI
void Calculadora::editPantalla1(){

  pantalla->setText(pantalla->text()+"1");

}

void Calculadora::editPantalla2(){

  pantalla->setText(pantalla->text()+"2");

}
void Calculadora::editPantalla3(){

  pantalla->setText(pantalla->text()+"3");

}
