#!/bin/bash
echo enter two numbers
read x
read y
loop=y
while [ "$loop"=y ]
do
echo Menu;
echo 1.Add
echo 2.Sub
echo 3.Mul
echo 4.div
echo 5.Exit
echo enter choice
read ch


case $ch in
	1) echo Answer is: `expr $x + $y`;;
	2) echo Answer is: `expr $x - $y`;;
	3) echo Answer is: `expr $x \* $y`;;
	5) loop=n ;;
	4) echo Answer is:`echo "scale=2; $x / $y" | bc` ;;
	*) echo Invalid entry;;
esac
done


