#include "mainwindow.h"

VentanaPrincipal::VentanaPrincipal(
    QWidget * parent,
    Qt::WindowFlags flags) : QMainWindow(parent,flags){

      //Creamos ahora el objeto declarado QTextEdit principal (editor central) y me paso a mi por parametro
      //para que tenga una relación de quién ha creado a quién.
      editorCentral = new QTextEdit(this);
      //Hacemos que el QTextEdit sea el widget principal
      setCentralWidget(editorCentral);
      //Poner un icono
      setWindowIcon(QIcon("./icon.png"));

      //Sección MENÚ
      //Crear el QAction de Salir para poder luego ya , implementarlo en nuestro menú
      accionSalir = new QAction(QIcon("./exit.png"),"&Salir",this); //Crea la accionSalir con el nombre Salir y la ventana principal
      //Conectar la señal accionsalir con la acción que va a realizar (signal trigger es la opción de "disparado")
      connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));

      //Por defecto  QMainWindow , ya tiene una Barra de menú , tenemos que añadir un objeto a la barra de menu
      //I Luego , agregar al Menu , las QAction
      fileMenu = menuBar()->addMenu("&Archivo"); //Añado a la Barra de menus la opción Archivo
      fileMenu->addAction(accionSalir); //Añado al menuArchivo la acciuon Salir

      //Menú Contextual
      editorCentral->addAction(accionSalir); //añadir al editor central con clic derecho el menu la opcin de salir
      editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu); //Politica de ejecución , es una constante ... añadir simepre
}
