#include "DInfoTabla.h"

DInfoTabla::DInfoTabla(QVector<Bola *> * bolasMain, QWidget *parent) : QDialog(parent) {

    setupUi(this);

    ModeloTabla * modelo = new ModeloTabla(bolasMain);
    tablaBolas->setModel(modelo);

}

ModeloTabla::ModeloTabla(QVector<Bola *> * bolasMain, QObject * parent){
    bolas = bolasMain;
}

int ModeloTabla::rowCount ( const QModelIndex & parent ) const {

    return bolas->size();
}

int ModeloTabla::columnCount ( const QModelIndex & parent ) const {

    return 4;
}

QVariant ModeloTabla::data ( const QModelIndex & index, int role ) const {

  int fila = index.row();
  int columna = index.column();

  qDebug() << "data() fila " << fila << "columna " << columna;

  if( role == Qt::DisplayRole ){

    switch (index.column()) {
      case 0: return QString::number(bolas->at(fila)->posX);
              break;
      case 1 :return QString::number(bolas->at(fila)->posY);
              break;
      case 2 :return QString::number(bolas->at(fila)->velX);
              break;
      case 3 :return QString::number(bolas->at(fila)->velY); 
              break;
    }

  }
  //para introducir un color al lado de cada nombre
  //if( role == Qt::DecorationRole ) return QColor("green");
  return QVariant();

}
