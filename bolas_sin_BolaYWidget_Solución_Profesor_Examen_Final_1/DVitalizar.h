#ifndef DVITALIZAR_H
#define DVITALIZAR_H
#include <QVector>
#include "Bola.h"
#include "ui_DVitalizar.h"
#include "WidgetVitalizar.h"


 class DVitalizar : public QDialog, public Ui::DVitalizar
{
     Q_OBJECT


 public:
    QVector<Bola *> *pBolas;
     DVitalizar(QVector<Bola *> *pBolas, QWidget *parent = 0);
     WidgetVitalizar * w;
    void verificarBola(Bola *b);
  public slots:
     void slotSiguiente();
     void slotAnterior();
     void slotBuscar();
     void slotActualizarVida();
};
#endif
