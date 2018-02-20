#ifndef WIDGETVITALIZAR_H
#define WIDGETVITALIZAR_H

#include <QTimer>
#include "Bola.h"
#include "ui_WidgetVitalizar.h"

 class WidgetVitalizar : public QWidget, public Ui::WidgetVitalizar
{
     Q_OBJECT

 public:
     WidgetVitalizar(Bola * b, QWidget *parent = 0);
	Bola *miBola;
  void ponBola(Bola *b);
  void actualizarVida();
  QTimer * temporizador;
  public slots:
  void slotAplicarVida();
  void slotProteger(int);
void slotParpadear();

};

#endif
