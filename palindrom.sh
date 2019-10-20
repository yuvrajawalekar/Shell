#!/bin/bash
echo "enter number: "
read n

rev=""

sd=0

on=$n

while [ $n -gt 0 ]


do

sd=$(( $n % 10 ))

rev=$( echo ${rev}${sd} )

n=$(( $n / 10 ))

done

if [ $on -eq $rev ];


then


  echo "Number is palindrome"


else


  echo "Number is NOT palindrome"


fi



