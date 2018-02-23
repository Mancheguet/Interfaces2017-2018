#include <QDebug>
#include "DInfoTabla.h"

 DInfoTabla::DInfoTabla(QVector<Bola*> *bolasPasadas, QWidget *parent)
      : QDialog(parent)
  {

	setupUi(this);

	ModeloTabla * modelo = new ModeloTabla(bolasPasadas);
	tabla->setModel(modelo);

}


ModeloTabla::ModeloTabla(QVector<Bola *> * bolasPasadas) : bolas(bolasPasadas) {
//	bolas = bolasPasdas;
}

int ModeloTabla::rowCount ( const QModelIndex & parent )const   {
	return bolas->size();
}

 int ModeloTabla::columnCount ( const QModelIndex & parent  )const  {
	return 4;
}
  QVariant ModeloTabla::data ( const QModelIndex & index, int role  ) const  {
	if (role != Qt::DisplayRole) 	return QVariant();

	int fila = index.row();
	int columna = index.column();
	qDebug() << "data() fila: " << fila<< " columna: " <<columna;
	switch (columna) {
		case 0 : return QString::number(bolas->at(fila)->posX);
			break;
		case 1 : return QString::number(bolas->at(fila)->posY);
			 break;
		case 2 : return QString::number(bolas->at(fila)->velX);
			break;
		case 3 : return QString::number(bolas->at(fila)->velY);
			break;
	};


}
