#!/bin/bash
echo entr string
read str
len=${#str}
for((i=$len-1;i>=0;i--))
do
reverse=$reverse${str:$i:1}
done
echo "Reverse is:  $reverse"

if [ $str = $reverse ]
then echo palindrome
else echo not palindrome
fi
