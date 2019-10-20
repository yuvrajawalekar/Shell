#!/bin/bash
echo enter num
read n
fact=1
for (( i=$n; i>0; i-- ))
do 
fact=$(($fact*$i))
done
echo "Fct of $n is: $fact"
