#include "DialogoDeshacer.h"

DialogoDeshacer::DialogoDeshacer(QWidget *parent)
     : QDialog(parent){

       setupUi(this);
       editor = NULL;

       connect(bDesHacer, SIGNAL(clicked()),
              this, SLOT(slotDeshacerRehacer()));
       connect(bReHacer, SIGNAL(clicked()),
              this, SLOT(slotDeshacerRehacer()));

     }

void DialogoDeshacer::slotDeshacerRehacer(){

  QPushButton * culpable = qobject_cast<QPushButton *>(sender());
  //Sender retorna un punter amb el objecte el cual ha sigut el que ha polsat

  //conecto aqui el editor porque al principio lo tengo a null
  connect(editor, SIGNAL(undoAvailable(bool)),
         this, SLOT(slotBotonVisible(bool)));
  connect(editor, SIGNAL(redoAvailable(bool)),
         this, SLOT(slotBotonVisibleRehacer(bool)));

  if(culpable==bDesHacer){
    editor->document()->undo();
  } else if (culpable==bReHacer){
      editor->document()->redo();
  }

}

void DialogoDeshacer::slotBotonVisible(bool activo){

  if(activo){
    bDesHacer->setEnabled(true);
  } else {
    bDesHacer->setEnabled(false);
  }

}

void DialogoDeshacer::slotBotonVisibleRehacer(bool activo){

  if(activo){
    bReHacer->setEnabled(true);
  } else {
    bReHacer->setEnabled(false);
  }

}
