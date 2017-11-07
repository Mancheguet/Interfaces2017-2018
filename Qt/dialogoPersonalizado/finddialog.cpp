#include <QtGui>
#include "finddialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

 FindDialog::FindDialog(QWidget *parent)
      : QDialog(parent)
  {

      //declaración botones
     check1 = new QCheckBox(tr("Check box 1"));
     check2 = new QCheckBox(tr("Check box 2"));
     check3 = new QCheckBox(tr("Check box 3"));

     button1 = new QPushButton(tr("Botón 1"));
     button2 = new QPushButton(tr("Botón 2"));
     button3 = new QPushButton(tr("Botón 3"));
     button4 = new QPushButton(tr("Cerrar"));
     button5 = new QPushButton(tr("Aceptar"));

     slider = new QSlider(Qt::Horizontal);

     combo1= new QComboBox();
     combo2= new QComboBox();
     combo3= new QComboBox();

     radio1 = new QRadioButton(tr("Radio1"));
     radio2 = new QRadioButton(tr("Radio2"));

     //creación de los layouts

     //botonesIzquierda
    QVBoxLayout *botonesIzquierda = new QVBoxLayout;
    botonesIzquierda->addWidget(button1);
    botonesIzquierda->addWidget(button2);
    botonesIzquierda->addWidget(button3);

    //checkboxderecha
    QVBoxLayout *checkboxderecha = new QVBoxLayout;
    checkboxderecha->addWidget(check1);
    checkboxderecha->addWidget(check2);
    checkboxderecha->addWidget(check3);
    checkboxderecha->addStretch();

    //juntar dosarriba en horizontal
    QHBoxLayout *checkConBotones = new QHBoxLayout;
    checkConBotones->addLayout(botonesIzquierda);
    checkConBotones->addLayout(checkboxderecha);

    //arriba horizontal con slider vertical
    QVBoxLayout *checkConBotonesSlider = new QVBoxLayout;
    checkConBotonesSlider->addLayout(checkConBotones);
    checkConBotonesSlider->addWidget(slider);

    //parte combo radiobutton 1
    QHBoxLayout *comboRadio1 = new QHBoxLayout;
    comboRadio1->addWidget(radio1);
    comboRadio1->addWidget(combo2);


    //parte combo radiobutton 2
    QHBoxLayout *comboRadio2 = new QHBoxLayout;
    comboRadio2->addWidget(radio2);
    comboRadio2->addWidget(combo3);


    //partecombobox
    QVBoxLayout *comboboxDerecha = new QVBoxLayout;
    comboboxDerecha->addStretch();
    comboboxDerecha->addWidget(combo1);
    comboboxDerecha->addLayout(comboRadio1);
    comboboxDerecha->addLayout(comboRadio2);

    //partefinalsinbotones
    QHBoxLayout *sinBotonesFinal = new QHBoxLayout;
    sinBotonesFinal->addLayout(checkConBotonesSlider);
    sinBotonesFinal->addLayout(comboboxDerecha);

    //botonesfinal
    QHBoxLayout *botonesdelFinal = new QHBoxLayout;
    botonesdelFinal->addWidget(button4);
    botonesdelFinal->addWidget(button5);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(sinBotonesFinal);
    mainLayout->addLayout(botonesdelFinal);
    setLayout(mainLayout);

 setWindowTitle(tr("Clase Perosnalizada"));
    //setFixedHeight(sizeHint().height());
 }
