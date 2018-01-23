#include "DInfoTabla.h"

DInfoTabla::DInfoTabla(QWidget *parent) : QDialog(parent) {

    setupUi(this);

    ModeloTabla * modelo = new ModeloTabla();
    tablaBolas->setModel(modelo);

}

ModeloTabla::ModeloTabla(QObject * parent){

}

int ModeloTabla::rowCount ( const QModelIndex & parent ) const {

    return 10;
}

int ModeloTabla::columnCount ( const QModelIndex & parent ) const {

    return 3;
}

QVariant ModeloTabla::data ( const QModelIndex & index, int role ) const {

  if( role == Qt::DisplayRole ){

    return QVariant(QString("Dada - ")+
      QString::number(index.column()+1)+
        QString(":")+QString::number(index.row()+1));

  }
  //para introducir un color al lado de cada nombre
  //if( role == Qt::DecorationRole ) return QColor("green");
  return QVariant();

}
