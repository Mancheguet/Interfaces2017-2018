#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QAction>
#include <QKeyEvent>
#include "Bola.h"
#include "DInformacion.h"
#include "DInfoBolas.h"
#include "DInfoTabla.h"
#include "DControlBolas.h"
/*** examen **/
#include "DCargaBolas.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:

     MainWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 ) ;
     virtual void paintEvent( QPaintEvent * e );
     void inicializarBolas();
     void inicializarMenus();

     QVector<Bola *> bolas;
     Bola * bolaJugador;
     QTimer *temporizador;
     QAction *accionDInformacion;
     QAction *accionDInfoBolas;
     QAction *accionDInfoTabla;
     QAction *accionDControlBolas;
     /*** examen **/
     QAction *accionAbrirFichero;
     QAction *accionDCargaBolas;


     DInfoBolas *dInfoBolas;
     DInfoTabla *dInfoTabla;
     DControlBolas *dControlBolas;
     DCargaBolas *dCargaBolas;
     void keyPressEvent(QKeyEvent *e);


public slots:
	void slotRepintar();
	void slotDInformacion();
	void slotDInfoBolas();
	void slotDInfoTabla();
	void slotDControlBolas();
  /*** examen **/
  bool slotAbrirFichero(QVector<Bola*> &);
  void slotDCargaBolas();

};

#endif
