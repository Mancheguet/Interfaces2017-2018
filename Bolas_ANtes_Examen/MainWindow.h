#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QVector>
#include <QPainter>
#include <QAction>
//Incluir estas dos para lo del menu (QMENU - QMENUBAR)
#include <QMenu>
#include <QMenuBar>

//Prueba de imagenes
#include <QPixmap>
#include <QImage>
//

#include <Bola.h>
#include <Dialog.h>
#include <DInfoTabla.h>
#include <DControlBolas.h>
#include "BolaYWidget.h"
#include "DVerColisiones.h"
#include "WidgetColision.h"

//Drag&Drop
#include <QDragEnterEvent>

class MainWindow : public QMainWindow{

    Q_OBJECT

    public:

        MainWindow (QWidget *parent = 0, Qt::WindowFlags flags = 0);

        QTimer *temporizador;

        QVector<BolaYWidget *> bolas;

        QAction *accionSalir;
        QAction *accionDialog;
        QAction *accionInfoTabla;
        QAction *accionControlBolas;
        QAction *accionDVerColisiones;

        QImage imagenBola;
        QPixmap *capturaPantalla;

        QMenu *fileMenu;

        BolaYWidget *bolaJugador;

        DInfoTabla *dInfoTabla;
        DControlBolas *dControlBolas;

        float posIX, posIY;

        void paintEvent (QPaintEvent *event);
        void inicializarBolas();
        void createActions();
        void createMenus();
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void dragEnterEvent ( QDragEnterEvent * event );
        void dropEvent ( QDropEvent * event );
        void anotarColision(Bola * bolaJugador, Bola * bola);

    public slots:

        void slotRepintar();
        void slotAbirDialog();
        void keyPressEvent(QKeyEvent *event);
        void slotInfoTabla();
        void slotControlBolas();
        void slotVerColisiones();

    private:

        void performDrag();
        QPoint startPos;

};

#endif
