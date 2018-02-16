#ifndef DVITALIZAR_H
#define DVITALIZAR_H
#include "ui_DVitalizar.h"
#include "Bola.h"
#include "WidgetVitalizar.h"
#include "QVector"
#include "QVBoxLayout"
#include "QLayout"

 class DVitalizar : public QDialog, public Ui::DVitalizar
{
     Q_OBJECT

 public:

     DVitalizar(QVector<Bola*> bolasAux, QWidget *parent = 0);
     //QVector<WidgetVitalizar*> * widgetsDeVitalizarAux,
     QVector<WidgetVitalizar*> widgetsDeVitalizar;
     int contador;


  public slots:
     void inicializarWidgetsVitalizar(QVector<Bola*> bolas);
     void slotSiguiente();
     void slotAnterior();
     void slotBuscar();
     void inciarUna();

};
#endif
