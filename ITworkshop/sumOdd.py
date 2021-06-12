num = int(input("Enter the number: "))
oddSum = 0
number = 1

while number <= num:
    oddSum += number
    number += 2

print("The sum of Odd numbers from 1 to {0} = {1}".format(num, oddSum))
