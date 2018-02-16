#ifndef WIDGETVITALIZAR_H
#define WIDGETVITALIZAR_H

#include "Bola.h"
#include "ui_WidgetVitalizar.h"
#include <QDialog>
#include <QWidget>

class WidgetVitalizar : public QDialog, public Ui::WidgetVitalizar{

 Q_OBJECT

 public:

     WidgetVitalizar(Bola * b, QWidget *parent = 0);
	   Bola *miBola;

     void pintarVida();
     void pintarNumero();

 public slots:

    void slotAplicar();

};

#endif
