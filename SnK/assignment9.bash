#!/bin/bash
echo -n "Enter number of terms in series: "
read number
a=0
b=1
echo "The Fibonacci series is: "
for((i=0; i<number; i++))
do
    echo "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done