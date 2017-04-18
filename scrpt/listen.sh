#!/bin/bash
while (true) ; 
do
	nc -l 5555
	#/home/kgoldstein/dev/BleedingEdge/buffy/giles/receiver/receiver --ponythreads=1 --ponynoblock --ponypinasio -w -l 127.0.0.1:5555
done
