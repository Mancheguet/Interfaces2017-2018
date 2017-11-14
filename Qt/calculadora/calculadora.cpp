#include <QtGui>
#include <QTextEdit>

#include <QApplication>
#include "xarxa.h"

#include "calculadora.h"

Calculadora::Calculadora(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    //connectar los botones para que salgan los numeros :
    connect(btn1, SIGNAL(clicked()), this, SLOT(editPantalla1()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(editPantalla2()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(editPantalla3()));
    connect(btnEnter, SIGNAL(clicked()), this, SLOT(editPantallaEnter()));

}

//EI BOBO , VAS PER LA PART DE CONTINUAR EL CPP , H DE CALCULADORA I DESPRES IMPLEMENTAL EL UI
void Calculadora::editPantalla1(){

  pantalla->setText(pantalla->text()+"1");

  if(pantalla->text() == "111"){
    Xarxa *dialogXarxa = new Xarxa;
    dialogXarxa->show();

  }

}

void Calculadora::editPantalla2(){

  pantalla->setText(pantalla->text()+"2");

}
void Calculadora::editPantalla3(){

  pantalla->setText(pantalla->text()+"3");

}
void Calculadora::editPantallaEnter(){

  Xarxa *dialogXarxa = new Xarxa;
  dialogXarxa->show();

}
