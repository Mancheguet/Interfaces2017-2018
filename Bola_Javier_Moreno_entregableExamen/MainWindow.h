#ifndef _MAINWINDOW_
#define _MAINWINDOW_

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QAction>
#include <QKeyEvent>
#include <QDebug>
#include "Bola.h"
#include "DInformacion.h"
#include "DInfoBolas.h"
#include "DInfoTabla.h"
#include "DControlBolas.h"
#include "DVitalizar.h"
#include "WidgetVitalizar.h"

class MainWindow : public QMainWindow {

Q_OBJECT

public:

     MainWindow ( QWidget * parent = 0, Qt::WindowFlags flags = 0 ) ;

     QVector<Bola *> bolas;
     QVector<WidgetVitalizar *> widgetsDeVitalizar;

     Bola * bolaJugador;

     QTimer *temporizador;

     QAction *accionDInformacion;
     QAction *accionDInfoBolas;
     QAction *accionDInfoTabla;
     QAction *accionDControlBolas;

     DInfoBolas *dInfoBolas;
     DInfoTabla *dInfoTabla;

     DControlBolas *dControlBolas;

     DVitalizar * dVitalizar;

     bool mouseEventDentro;

     virtual void paintEvent( QPaintEvent * e );
     void inicializarBolas();
     //void inicializarWidgetsVitalizar();
     void inicializarMenus();
     void keyPressEvent(QKeyEvent *e);
     void mousePressEvent(QMouseEvent *event);;

public slots:

	void slotRepintar();
	void slotDInformacion();
	void slotDInfoBolas();
	void slotDInfoTabla();
	void slotDControlBolas();

};

#endif
