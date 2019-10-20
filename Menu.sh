#!/bin/bash

echo entr  2 strings
read a
read b

loop=y

while [ "$loop" = y ];
do
echo string ops
echo 1.length
echo 2. copy
echo 3.concat
echo 4.compre
echo 5.reverse
echo 6.exit

echo enter choice
read x

case $x in
	1) echo len of $a is ${#a};;
	2) c=$a;
	   echo copy of $a in  $c;;
	3) echo concat string ==$a$b$c;;
	4)if [ $a == $b ]
	then 
		echo Equal
	else
		echo non equal
	fi;;
	5) echo reverse 
	   echo $a | rev;;
	6) loop=n;;
	*) echo wrong choice ;;
esac
done
