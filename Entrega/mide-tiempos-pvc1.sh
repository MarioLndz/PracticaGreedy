#!/bin/bash 
#echo "" >> salida.dat
printf "" > pvc1.dat

i=5000
while [ "$i" -le 125000 ]
do
	# Generamos los puntos	
	./generador-pvc $i
  	
	# Ejecutamos los puntos
	./pvc1 data.txt >> pvc1.dat

	echo "Terminado $i" 
	
	i=$(( $i + 5000 ))
done