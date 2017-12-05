#include "mainwindow.h"
#include "QMessageBox"

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

  //Bucle de creación de acciones :
  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    accionesFicherosRecientes[i] = new QAction(QIcon("./doc.png"),"",this);
    accionesFicherosRecientes[i] -> setVisible(false);
    connect(accionesFicherosRecientes[i],SIGNAL(triggered()),
                          this, SLOT(slotAbrirFicheroReciente()));
  }

}

void VentanaPrincipal::createMenus(){

  //Por defecto  QMainWindow , ya tiene una Barra de menú , tenemos que añadir un objeto a la barra de menu
  //I Luego , agregar al Menu , las QAction
  fileMenu = menuBar()->addMenu("&Archivo"); //Añado a la Barra de menus la opción Archivo
  fileMenu->addAction(accionSalir); //Añado al menuArchivo la acciuon Salir
  fileMenu->addAction(accionAbrir); //añadir abrir
  fileMenu->addAction(accionGuardar); //añadir guardar
  fileMenu->addAction(accionNuevo); //añadir nuevo

  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    fileMenu->addAction(accionesFicherosRecientes[i]);
  }

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

//Crea la Status Bar con el numero de lineas y otro con el numero de caracteres que se va actlualizando

void VentanaPrincipal::createStatusBar(){

  labelNumeroLineas = new QLabel(" Número de líneas : 1");
  statusBar()->addWidget(labelNumeroLineas);
  labelNumeroCaracteres = new QLabel(" Número carácteres : 0");
  statusBar()->addWidget(labelNumeroCaracteres);
  rutaArchivoActual = new QLabel("Ruta :");
  statusBar()->addWidget(rutaArchivoActual);

}

//Metodo para abrir un fichero
bool VentanaPrincipal::abrirFichero(QString nombre){

  editorCentral->document()->clear();

  QFile archivo(nombre);
  if(!archivo.open(QIODevice::ReadOnly)){
    QMessageBox::warning(this, tr("Editor"),
                             tr("Cannot read file 1:\n2.")
                             .arg(archivo.fileName())
                             .arg(archivo.errorString()));
    return false;
  }

  QTextStream stream(&archivo);

  while(!stream.atEnd()){
    editorCentral->append(stream.readLine());
  }

  rutaArchivoActual->setText(" Ruta : "+archivo.fileName());
  establecerFicheroActual(nombre);

  return true;
}

void VentanaPrincipal::establecerFicheroActual(QString ruta){

  //si el numero del array es menro al Max , borra y añade al principio el archivo
  if(ficherosRecientes.size()<MAX_RECENT_FILES){
    ficherosRecientes.removeAll(ruta);
    ficherosRecientes.prepend(ruta);
  } else {
    //sino, lo que hago es borrar el útlimo elemento y añadir el nuevo elemento
    ficherosRecientes.removeAll(ficherosRecientes[ficherosRecientes.size()-1]);
    ficherosRecientes.removeAll(ruta);
    ficherosRecientes.prepend(ruta);
  }

  //iterador que elimina los ficheros que ya no estan en el sistema
  QMutableStringListIterator i(ficherosRecientes);
  while(i.hasNext()){
    if(!QFile::exists(i.next()))
      i.remove();
  }

  //fique tots a visible false
  for (int i = 0; i < MAX_RECENT_FILES; i++) {
    accionesFicherosRecientes[i]->setVisible(false);
  }

  //ara, clava i fica a true les cosses
  QMutableStringListIterator ii(ficherosRecientes);
  int indice = 0;
  while(ii.hasNext() && indice<MAX_RECENT_FILES){
      QString ruta = ii.next();
      QString nombreCorto = QFileInfo(ruta).fileName();
      accionesFicherosRecientes[indice]->setText(nombreCorto);
      accionesFicherosRecientes[indice]->setVisible(true);
      //Le metememos por el data un qvariant que luego usaremos para abrir el archivo
      accionesFicherosRecientes[indice]->setData(QVariant(ruta));

      editorCentral->append(ruta);
      indice++;
  }

}

/////////////////
/////SLOTS//////
///////////////

void VentanaPrincipal::slotAbrir(){

  //Al apretar en abrrir , se crea y se abre un FIleDIalog de bsucar documetno
  QString fileName = QFileDialog::getOpenFileName(
  this, tr("Abrir archivo"),"/home/vesprada/Baixades","*.txt");

  //Si se selecciona algun archivo -> Se pone su tecto en el document del editorCentral
  if(!fileName.isEmpty()){
    editorCentral->document()->setPlainText(fileName);
  } else{
    //sino , se pone que ningún archivo ha sido seleccionado
    editorCentral->document()->setPlainText("Ningún archivo seleccionado.");
  }

  //Si el texto se ha modificado y quieres abrir otro documento , te preguntará si quieres
  //abrir otro documento sin guardar antes el que estas editando.
  if(txtModificado){
    int a = QMessageBox::warning(this,
        tr("Nuevo"),
        tr("¿Estás seguro de querer borrar?"),
        QMessageBox::Yes | QMessageBox::No);

      if(a == QMessageBox::Yes){
      abrirFichero(fileName);
    } else if(a == QMessageBox::No){
      return;
    }
  } else{
    abrirFichero(fileName);
  }


}

void VentanaPrincipal::slotGuardar(){

}

void VentanaPrincipal::slotActualizarBarraEstado(){

  txtModificado = true; //Control de cambio de texto.
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

    //Al apretar en nuevo , lo que vamos a hacer es preguntar si quieres borrar el
    //archvio actual o no
    if(txtModificado){
      int r = QMessageBox::warning(this,
          tr("Nuevo"),
          tr("¿Estás seguro de querer borrar?"),
          QMessageBox::Yes | QMessageBox::No);

      if(r == QMessageBox::Yes){
        editorCentral->document()->clear();
        rutaArchivoActual->setText(" Ruta : ");
      } else if(r == QMessageBox::No){
        return;
      }
    } else {
      editorCentral->document()->clear();
      txtModificado = false;
      return;
    }

}

//Metodo para editar el CloseEvent (cuando se cierra, ya sea por close() o por el aspa en ventana )
void VentanaPrincipal::closeEvent(QCloseEvent *event){

    int r = QMessageBox::warning(this,
        tr("Nuevo"),
        tr("¿Estás seguro de que quieres cerrar?"),
        QMessageBox::Yes | QMessageBox::No);

    if(r == QMessageBox::Yes){
      event->accept();
    } else if(r == QMessageBox::No){
      event->ignore();
      return;
    }

}

void VentanaPrincipal::slotAbrirFicheroReciente(){
  
    //////////////////////////////////////////////////////////////////////////
    /////////// CASTING DE QOBJECT A QACTION !!!!!!!!!!!!!!!! ////////////////
    //////////////////////////////////////////////////////////////////////////
    QAction * culpable = qobject_cast<QAction *>(sender());
    //Recuperamos en una QSTRING la ruta del archivo
    QString rutaArchivo = culpable->data().toString();
    abrirFichero(rutaArchivo);

}
