#!/bin/bash

#OJO: adaptar las leyendas a los nombres de las variables. En el eje Y se miden tiempos y en el eje X es el tamaño del ejemplar.
cat << _end_ | gnuplot
set terminal postscript eps color
set output "seleccion.eps"
set key right bottom
set xlabel "Tiempo"
set ylabel "Numero de elementos"
 plot 'datosFinalesSeleccion.txt' using 1:2 t "Tiempos Reales" , 'datosFinalesSeleccion.txt' using 1:3 t "Tiempos Estimados" w l
_end_
