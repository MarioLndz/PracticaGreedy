#!/bin/bash 
#echo "" >> salida.dat
printf "" > pvc3.dat

i=100
while [ "$i" -le 3000 ]
do
	# Generamos los puntos	
	./generador-pvc $i
	printf "PUNTOS GENERADOS\t"
  	
	# Ejecutamos los puntos
	./pvc3 data_pvc.txt >> pvc3.dat

	echo "Terminado $i" 
	
	i=$(( $i + 100 ))
done
