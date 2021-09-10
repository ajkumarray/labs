list = []
sum = 0
num = int(input("Enter a number: "))
for i in range(1, num):
    list.append(i)
print("The list is: ", list)
for i in list:
    if i % 2 != 0:
        sum = sum + i
        
print("Sum of odd numbers from 1 -", num, "is:", sum)
