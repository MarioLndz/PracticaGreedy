#!/bin/bash 
#echo "" >> salida.dat
printf "" > pvc2.dat

i=100
while [ "$i" -le 3000 ]
do
	# Generamos los puntos	
	./generador-pvc $i
  	
	# Ejecutamos los puntos
	./pvc2 data_pvc.txt >> pvc2.dat

	echo "Terminado $i" 
	
	i=$(( $i + 100 ))
done
