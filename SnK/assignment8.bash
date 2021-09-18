#!/bin/bash
echo -n "Enter a number: "
read number
sum=0
for((i=1; i<=number; i++))
do
    sum=$[ $sum + $i ]
done
echo "The sum of first $number natural numbers is $sum"