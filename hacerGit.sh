#!/bin/bash
#Javier Moreno

#hacer git de toda la carpeta
git add *
#hacer commit - cambiar el mensaje por el que queremos
#Parte comentario automatico
echo 'Dime el mensaje para el commit : '
read nombre

git commit -m $nombre
#descomentar esta linea para crear el origin
#git remote add origin https://github.com/Mancheguet/Interfaces2017-2018.git
#hacer el push para subir los archivos
git push -u origin master
