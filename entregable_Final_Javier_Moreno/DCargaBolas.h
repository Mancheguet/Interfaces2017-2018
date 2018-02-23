#ifndef DCARGABOLAS_H
#define DCARGABOLAS_H
#include <QVector>
#include <QTimer>
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QFrame>
#include <QColor>
#include <QPaintEvent>
#include <QMouseEvent>
#include "Bola.h"
#include "ui_DCargaBolas.h"
#include "WidgetDatosBola.h"

class DCargaBolas : public QDialog, public Ui::DCargaBolas
{
     Q_OBJECT

 public:
   // los argumentos puestos aquí son los necesarios para entregar el código
   // y que compile, si lo necesitas modifícalo para el ejercicio.
     DCargaBolas( int an, int al, QVector<Bola*> &bolas, QVector<Bola*> * punteroFueraAux, QWidget *parent = 0);

     QVector<Bola *> bolasCargar;
     QWidget * widget;
     QColor * colorRecuadro;
     QVector<Bola*> * punteroFuera;
     //QVector<WidgetDatosBola *> widgetsDatosBola;
     void cambiarColorFondo(QColor * color);
     void cambioColor();
     void accept();

 public slots:

    void slotCambioPestanya(int numPestanya);
    void slotVerLista();

};

class ModeloTablaDentro : public QAbstractTableModel {

public :

    Bola * bola;
    ModeloTablaDentro(Bola * bolaPasada);

    int rowCount ( const QModelIndex & parent = QModelIndex() ) const ;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const ;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const ;

};


#endif
