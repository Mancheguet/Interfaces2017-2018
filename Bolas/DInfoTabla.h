#ifndef DINFOTABLA_H
#define DINFOTABLA_H

#include <QAbstractTableModel>
#include <QDialog>
#include <QModelIndex>
#include <QVector>

#include <QDebug>

#include "ui_DInfoTabla.h"

#include "Bola.h"
#include "BolaYWidget.h"


class DInfoTabla : public QDialog, public Ui::DInfoTabla {

    Q_OBJECT

    public:

        DInfoTabla( QVector<BolaYWidget *> * bolasMain, QWidget *parent=0);

};

class ModeloTabla : public QAbstractTableModel {
public:

    ModeloTabla ( QVector<BolaYWidget *> * bolasMain, QObject * parent = 0 );

    QVector<BolaYWidget *> * bolas;

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const ;

    int columnCount ( const QModelIndex & parent = QModelIndex() ) const ;

    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;
};

#endif
