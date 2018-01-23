#ifndef DINFOTABLA_H
#define DINFOTABLA_H

#include <QAbstractTableModel>
#include <QDialog>
#include <QModelIndex>
#include <QVector>

#include "ui_DInfoTabla.h"

#include "Bola.h"


class DInfoTabla : public QDialog, public Ui::DInfoTabla {

    Q_OBJECT

    public:

        DInfoTabla(QWidget *parent=0);

};

class ModeloTabla : public QAbstractTableModel {
public:

    ModeloTabla ( QObject * parent = 0 );

    int rowCount ( const QModelIndex & parent =

    QModelIndex() ) const ;

    int columnCount ( const QModelIndex & parent = QModelIndex() ) const ;

    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;
};

#endif
