#!/bin/bash 
#echo "" >> salida.dat
printf "" > jukebox.dat

i=5000
while [ "$i" -le 125000 ]
do
	# Generamos los puntos	
	./generador $i
  	
	# Ejecutamos los puntos
	./voraz data.txt >> jukebox.dat

	echo "Terminado $i" 
	
	i=$(( $i + 5000 ))
done
