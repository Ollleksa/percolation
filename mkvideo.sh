#!/bin/bash

numfiles=(data/*)
numfiles=${#numfiles[@]}
 
for (( i=1; i<=${numfiles}; i++ ));
do
	gnuplot -e "filename = 'data/data${i}.dat'; filename2 = 'plot/plot${i}.png' " gpl.p
done

ffmpeg -framerate 4  -i 'plot/plot%d.png'  -c:v libx264 percolation.mp4
