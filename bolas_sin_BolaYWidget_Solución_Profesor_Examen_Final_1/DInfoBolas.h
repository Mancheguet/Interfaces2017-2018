#ifndef DINFOBOLAS_H
#define DINFOBOLAS_H
#include <QVector>
#include <QTimer>
#include "Bola.h"
#include "ui_DInfoBolas.h"

 class DInfoBolas : public QDialog, public Ui::DInfoBolas 
{
     Q_OBJECT

 public:	
     QTimer * temporizador;
     QVector<Bola * > bolas;
     DInfoBolas(QVector<Bola*> bolas, QWidget *parent = 0);
public slots:
	void mostrar();
};
#endif

