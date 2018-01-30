#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H

#include <QAbstractTableModel>
#include <QDialog>
#include <QModelIndex>
#include <QVector>
#include <QPushButton>
#include <QWidget>
#include <QDebug>

#include "ui_DControlBolas.h"

#include "Bola.h"
#include "WidgetBola.h"
#include "BolaYWidget.h"


class DControlBolas: public QDialog, public Ui::DControlBolas {

    Q_OBJECT

    public:

      DControlBolas(QVector<BolaYWidget *> * bolasMain, QWidget *parent=0);
      QVector<BolaYWidget *> * bolas;

    public slots:

      void slotCambioPestana(int);
      void slotIgualar();
};

#endif
