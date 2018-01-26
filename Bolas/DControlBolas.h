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


class DControlBolas: public QDialog, public Ui::DControlBolas {

    Q_OBJECT

    public:

      DControlBolas(QVector<Bola *> * bolasMain, QWidget *parent=0);

    public slots:

      void slotCambioPestana(int);
};

#endif
