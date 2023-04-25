#!/bin/bash 
#echo "" >> salida.dat
printf "" > dist_pvc1.dat

i=100
while [ "$i" -le 3000 ]
do
	# Generamos los puntos	
	./generador-pvc $i
	printf "PUNTOS GENERADOS\t"
  	
	# Ejecutamos los puntos
	./pvc1 data_pvc.txt >> dist_pvc1.dat

	echo "Terminado $i" 
	
	i=$(( $i + 100 ))
done
