#!/bin/bash
echo enter num
read n
i=2
z=0
x=1
while [ $i -lt $n ]
do
	x=$(($n % $i))
	if [ $x -eq $z  ]; then echo not prime
	exit
       
	else i=$(($i+1))
	fi

	
done
	echo prime number

