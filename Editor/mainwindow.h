#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
//Incluir estas dos para lo del menu (QMENU - QMENUBAR)
#include <QMenu>
#include <QMenuBar>

#include <QToolBar>
#include <QStatusBar>

#include <QLabel>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include <QCloseEvent>
#include <QMutableStringListIterator>
//incluir la parte del finddialogo!!!!
#include "finddialog.h"
#include "DialogoDeshacer.h"
#include "IntroducirPalabra.h"

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);
    static const int MAX_RECENT_FILES = 5;

private:
    QTextEdit *editorCentral;

    QAction *accionSalir;
    QAction *accionGuardar;
    QAction *accionAbrir;
    QAction *accionNuevo;
    QAction *accionesFicherosRecientes[MAX_RECENT_FILES];
    QAction *accionBuscar;
    QAction *accionDesReHacer;
    QAction *accionAnadir;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *palabrasMenu;

    bool txtModificado;

    QToolBar *barraArchivo;
    QToolBar *barraSalir;

    QLabel *labelNumeroLineas;
    QLabel *labelNumeroCaracteres;
    QLabel *rutaArchivoActual;

    bool abrirFichero(QString nombre);

    QStringList ficherosRecientes;
    QStringList palabrasIntroducidas;

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void establecerFicheroActual(QString);
    void actualizarPalabras();
    void createContextualMenu();

private slots:
    void slotAbrir();
    void slotGuardar();
    void slotActualizarBarraEstado();
    void slotNuevo();
    void closeEvent(QCloseEvent *event);
    void slotAbrirFicheroReciente();
    void slotBuscar();
    void slotFindNext(const QString &, Qt::CaseSensitivity);
    void slotFindPrevious(const QString &, Qt::CaseSensitivity);
    void slotDesRehacer();
    void slotAnadir();
    void slotAccionPalabra();

};

#endif
