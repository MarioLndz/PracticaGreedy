#!/bin/bash 
#echo "" >> salida.dat
printf "" > jukebox.dat

i=400
while [ "$i" -le 10000 ]
do
	# Generamos los puntos	
	./generador $i
  	
	# Ejecutamos los puntos
	./voraz data_jukebox >> jukebox.dat

	echo "Terminado $i" 
	
	i=$(( $i + 400))
done
