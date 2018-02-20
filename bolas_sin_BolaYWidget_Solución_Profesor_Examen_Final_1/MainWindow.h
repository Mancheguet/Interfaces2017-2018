#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QAction>
#include <QKeyEvent>
#include  <QMouseEvent>
#include "Bola.h"
#include "DInformacion.h"
#include "DInfoBolas.h"
#include "DInfoTabla.h"
#include "DControlBolas.h"
#include "DVitalizar.h"


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

     DInfoBolas *dInfoBolas;
     DInfoTabla *dInfoTabla;
     DControlBolas *dControlBolas;
    DVitalizar *dVitalizar;
      void keyPressEvent(QKeyEvent *e);
      void mousePressEvent(QMouseEvent *e);

public slots:
	void slotRepintar();
	void slotDInformacion();
	void slotDInfoBolas();
	void slotDInfoTabla();
	void slotDControlBolas();

};

#endif
