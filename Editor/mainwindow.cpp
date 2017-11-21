#include "mainwindow.h"

VentanaPrincipal::VentanaPrincipal(
    QWidget * parent,
    Qt::WindowFlags flags) : QMainWindow(parent,flags){

      //Creamos ahora el objeto declarado QTextEdit principal (editor central) y me paso a mi por parametro
      //para que tenga una relación de quién ha creado a quién.
      editorCentral = new QTextEdit(this);
      connect(editorCentral,SIGNAL(textChanged()),this, SLOT(slotActualizarBarraEstado()));

      //Hacemos que el QTextEdit sea el widget principal
      setCentralWidget(editorCentral);
      //Poner un icono
      setWindowIcon(QIcon("./icon.png"));

      //llamar a los dos metodos de creación
      createActions();
      createMenus();
      createToolBars();
      createStatusBar();

}

////////////////////////////
//// METODOS CREACIÓN /////
//////////////////////////

void VentanaPrincipal::createActions(){

  //Sección MENÚ
  //Crear el QAction de Salir para poder luego ya , implementarlo en nuestro menú
  accionSalir = new QAction(QIcon("./exit.png"),"&Salir",this); //Crea la accionSalir con el nombre Salir y la ventana principal
  //Conectar la señal accionsalir con la acción que va a realizar (signal trigger es la opción de "disparado")
  connect(accionSalir,SIGNAL(triggered()),this, SLOT(close()));
  accionSalir->setShortcut(tr("Ctrl+q"));

  //ABRIR
  accionAbrir = new QAction(QIcon("./abrir.png"),"&Abrir",this);
  connect(accionAbrir,SIGNAL(triggered()),this, SLOT(slotAbrir()));
  accionAbrir->setShortcut(tr("Ctrl+o"));

  //GUARDAR
  accionGuardar = new QAction(QIcon("./guardar.png"),"&Guardar",this);
  connect(accionGuardar,SIGNAL(triggered()),this, SLOT(slotGuardar()));
  accionGuardar->setShortcut(tr("Ctrl+s"));

  //Nuevo
  accionNuevo = new QAction(QIcon("./nuevo.png"),"&Nuevo",this);
  connect(accionNuevo,SIGNAL(triggered()),this, SLOT(slotNuevo()));
  accionNuevo->setShortcut(tr("Ctrl+n"));

}

void VentanaPrincipal::createMenus(){

  //Por defecto  QMainWindow , ya tiene una Barra de menú , tenemos que añadir un objeto a la barra de menu
  //I Luego , agregar al Menu , las QAction
  fileMenu = menuBar()->addMenu("&Archivo"); //Añado a la Barra de menus la opción Archivo
  fileMenu->addAction(accionSalir); //Añado al menuArchivo la acciuon Salir
  fileMenu->addAction(accionAbrir); //añadir abrir
  fileMenu->addAction(accionGuardar); //añadir guardar
  fileMenu->addAction(accionNuevo); //añadir nuevo

  //Menú Contextual
  editorCentral->addAction(accionSalir); //añadir al editor central con clic derecho el menu la opcin de salir
  editorCentral->addAction(accionAbrir); //añadir abrir
  editorCentral->addAction(accionGuardar); //añadir guardar
  editorCentral->addAction(accionNuevo); //añadir nuevo

  editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu); //Politica de ejecución , es una constante ... añadir simepre

}

void VentanaPrincipal::createToolBars(){

    //creación de la toolbar
    barraArchivo = addToolBar("Archivo");
    barraSalir = addToolBar("Salir");
    //añadir a la toolbar archivo , el action abrir , guardar y nuevo
    barraArchivo->addAction(accionAbrir);
    barraArchivo->addAction(accionGuardar);
    barraArchivo->addAction(accionNuevo); //añadir nuevo
    //añadir a la toobar salir , el action salir
    barraSalir->addAction(accionSalir);

}

void VentanaPrincipal::createStatusBar(){

  labelNumeroLineas = new QLabel(" Número de líneas : 1");
  statusBar()->addWidget(labelNumeroLineas);
  labelNumeroCaracteres = new QLabel(" Número carácteres : 0");
  statusBar()->addWidget(labelNumeroCaracteres);

}

/////////////////
/////SLOTS//////
///////////////

void VentanaPrincipal::slotAbrir(){

}

void VentanaPrincipal::slotGuardar(){

}

void VentanaPrincipal::slotActualizarBarraEstado(){

  //numero lineas
  int numero = editorCentral->document()->lineCount(); //Sacar numero lineas
  QString cadena = QString::number(numero); //Pasar de int a string
  labelNumeroLineas->setText(" Número de líneas : "+cadena);

  //numero carácteres
  int numero2 = editorCentral->document()->characterCount(); //Sacar numero caracteres
  QString cadena2 = QString::number(numero2-1); //Pasar de int a string
  labelNumeroCaracteres->setText(" Número de carácteres : "+cadena2);

}

void VentanaPrincipal::slotNuevo(){

    editorCentral->document()->clear(); //limpiar el documento

}
