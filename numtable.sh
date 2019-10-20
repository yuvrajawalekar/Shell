#!/bin/bash
echo enter num
read n
i=1
total=0

while [ $i -le 10 ];

do

total=$(( $i * $n ))

echo "$n * $i = $total"

i=$(($i + 1))

done

