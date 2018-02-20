#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H
#include <QVector>
#include <QTimer>
#include <QAbstractTableModel>
#include <QModelIndex>
#include "Bola.h"
#include "ui_DControlBolas.h"

 class DControlBolas : public QDialog, public Ui::DControlBolas 
{
     Q_OBJECT

 public:	
     DControlBolas(QVector<Bola*> bolas,QWidget *parent = 0);

 public slots:
	void slotCambioPestanya(int numPestanya);
};

#endif

