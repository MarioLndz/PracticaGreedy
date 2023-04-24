#!/bin/bash 
#echo "" >> salida.dat
printf "" > jukebox.dat

i=500
while [ "$i" -le 12500 ]
do
	# Generamos los puntos	
	./generador $i
  	
	# Ejecutamos los puntos
	./voraz data_jukebox >> jukebox.dat

	echo "Terminado $i" 
	
	i=$(( $i + 500 ))
done
