#ifndef DINFOTABLA_H
#define DINFOTABLA_H
#include <QVector>
#include <QTimer>
#include <QAbstractTableModel>
#include <QModelIndex>
#include "Bola.h"
#include "ui_DInfoTabla.h"

 class DInfoTabla : public QDialog, public Ui::DInfoTabla
{
     Q_OBJECT

 public:
     DInfoTabla(QVector<Bola*> * bolas, QWidget *parent = 0);

};


class ModeloTabla : public QAbstractTableModel {

public :

     QVector<Bola*> * bolas ;
    ModeloTabla(QVector<Bola *> * bolasPasadas);

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const ;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const ;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;



};

#endif
