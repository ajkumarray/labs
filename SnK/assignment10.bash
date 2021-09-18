#!/bin/bash
echo "Enter the number of elements: "
read number
echo "Enter elements of array: "
read all_elements
echo "Enter element to be searched: "
read element
found="NOT FOUND"
for e in $all_elements
do
    if[$element == $e];
    then
            echo "Successful search!";
            found="FOUND";
            break;
    fi
done
if[$found == "NOT FOUND"];
then
    echo "Not Found!";
fi

