#include <QDebug>
#include <QPushButton>
#include "DCargaBolas.h"

/* el siguiente include será necesario */
#include "WidgetDatosBola.h"

// si haces el botón Lista podrás tomar de aquí el diálogo
#include "DInfoBolas.h"


 DCargaBolas::DCargaBolas( int an, int al, QVector<Bola*> &bolas, QVector<Bola*> * punteroFueraAux, QWidget *parent)
      : QDialog(parent)
  {

  // de alguna manera, estas variables llegarán a dar valor a las que aparecen
  // mas abajo en este ejemplo.
    int anchura = an;
    int altura = an;
    bolasCargar=bolas;
    punteroFuera = punteroFueraAux;
    colorRecuadro = new QColor(100,100,100,255);

	setupUi(this);


    connect(tabBolas,SIGNAL(currentChanged(int)),
		                this,SLOT(slotCambioPestanya(int)));
    connect(botonVerLista,SIGNAL(clicked()),
                		this,SLOT(slotVerLista()));

	  while (tabBolas->count() > 0) tabBolas->removeTab(0);

	  for (int i = 0;i<bolas.size(); i++){

      WidgetDatosBola * widgetMomento = new WidgetDatosBola(bolasCargar.at(i));
      ModeloTablaDentro * modelo = new ModeloTablaDentro(bolasCargar.at(i));
    	widgetMomento->tablaDatos->setModel(modelo);
		  tabBolas->addTab(widgetMomento, QString("Pestanya")+QString::number(i));

    }

    widget = new QWidget();
    layoutLineas->layout()->addWidget(widget);
    cambiarColorFondo(colorRecuadro);

}

void DCargaBolas::accept(){
    qDebug() << "Aceptado";
    for (int i = 0; i < tabBolas->count(); i++) {
      WidgetDatosBola *widgetMomento = qobject_cast<WidgetDatosBola *> (tabBolas->widget(i));
      if(widgetMomento->checkIncluir->isChecked()){
        qDebug() << "Incluir!";
        punteroFuera->append(widgetMomento->miBola);
      }
    }
    this->close();
}

void DCargaBolas::slotCambioPestanya(int numPestanya){
  cambioColor();
}

void DCargaBolas::cambioColor(){

  WidgetDatosBola *widgetMomento = qobject_cast<WidgetDatosBola *> (tabBolas->widget(tabBolas->currentIndex()));
  if (widgetMomento != NULL ){
    qDebug() << "color" << widgetMomento->miBola->color.red();
    colorRecuadro = new QColor(widgetMomento->miBola->color.red(),widgetMomento->miBola->color.green(),widgetMomento->miBola->color.blue(),255);
    cambiarColorFondo(colorRecuadro);
  }

}

void DCargaBolas::slotVerLista(){

  QVector<Bola *> bolasMomento;
  for (int i = 0; i < tabBolas->count(); i++) {
    WidgetDatosBola *widget = qobject_cast<WidgetDatosBola *> (tabBolas->widget(i));
    bolasMomento.append(widget->miBola);
  }
  DInfoBolas * deinfobolas = new DInfoBolas(bolasMomento,this);
  deinfobolas->show();

}

ModeloTablaDentro::ModeloTablaDentro(Bola * bolaPasada) : bola(bolaPasada) {}

int ModeloTablaDentro::rowCount ( const QModelIndex & parent )const   {
	return 5;
}

 int ModeloTablaDentro::columnCount ( const QModelIndex & parent  )const  {
	return 2;
}
  QVariant ModeloTablaDentro::data ( const QModelIndex & index, int role  ) const  {
	if (role != Qt::DisplayRole) 	return QVariant();

	int fila = index.row();
	int columna = index.column();
	qDebug() << "data() fila: " << fila<< " columna: " <<columna;

  switch (fila) {
    case 0:
      switch (columna) {
        case 0: return "Posición X";
        break;
        case 1: return bola->posX;
        break;
      }
      break;
    case 1:
        switch (columna) {
          case 0: return "Posición Y";
          break;
          case 1: return bola->posY;
          break;
        }
    break;
    case 2:
        switch (columna) {
          case 0: return "Rojo";
          break;
          case 1: return bola->color.red();
          break;
        }
    break;
    case 3:
        switch (columna) {
          case 0: return "Verde";
          break;
          case 1: return bola->color.green();
          break;
        }
    break;
    case 4:
        switch (columna) {
          case 0: return "Azul";
          break;
          case 1: return bola->color.blue();
          break;
        }
    break;
  }

  return "Dato no contemplado";
  /*
	switch (columna) {
		case 0 : return QString::number(bolas->at(fila)->posX);
			break;
		case 1 : return QString::number(bolas->at(fila)->posY);
			 break;
		case 2 : return QString::number(bolas->at(fila)->velX);
			break;
		case 3 : return QString::number(bolas->at(fila)->velY);
			break;
  */
	};



/*la siguiente función sirve para cambiar el color de fondo de un WidgetDatosBola
  este widget se crea aquí mismo sólo como demostración tú deberás descubrir cómo
  implementar lo que pide el enunciado.
  puedes adaptarla para que cambie de color de fondo el rectángulo en la parte inferior
  del diálogo*/
void DCargaBolas::cambiarColorFondo(QColor * color){
  qDebug()<< "numero" << layoutLineas->count();

  QLayoutItem *child;
  while ((child = layoutLineas->takeAt(0)) != 0) {
      delete child;
  }

  //layoutLineas->removeWidget(widget);
  widget = new QWidget(); //quita la "w." en la versión final
  //widget->resize(400,400);
  widget->setBackgroundRole(QPalette::Window);
  QPalette Pal(widget->palette());
  Pal.setColor(QPalette::Background, color->rgb());
  widget->setAutoFillBackground(true);
  widget->setPalette(Pal);
  layoutLineas->layout()->addWidget(widget);
}


/* la siguiente función es un paintEvent que pinta dos rayas a partir de ciertos datos:
  width() y height() del widget en el que se pintan las líneas
  posX y posY la posición de la bola en el juego (en QMainWindow)
  anchura y altura son la anchura y altura de la ventana de juego */

//quita el siguiente #ifdef cuando lo tengas claro
#ifdef PAINTEVENT_EJERCICIO
void paintEvent(QPaintEvent * e){

   float ratioX = width()*0.99 / anchura;
   float ratioY = height()*0.99 / altura;

  float x = ratioX * posX ;
  float y = ratioY * posY ;

  QPainter pintor(this);
  pintor.drawLine(x,0,x,height());
  pintor.drawLine(0,y,width(),y);

}
#endif
