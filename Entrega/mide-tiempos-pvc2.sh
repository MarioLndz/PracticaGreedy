#!/bin/bash 
#echo "" >> salida.dat
printf "" > pvc2.dat

i=50000
while [ "$i" -le 1250000 ]
do
	# Generamos los puntos	
	./generador-pvc $i
  	
	# Ejecutamos los puntos
	./pvc2 data_pvc >> pvc2.dat

	echo "Terminado $i" 
	
	i=$(( $i + 50000 ))
done
