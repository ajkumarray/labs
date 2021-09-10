list = []
num = int(input("Enter a number: "))
for i in range(1, num):
    list.append(i)
print("The list is: ", list)
for i in list:
    if i % 2 != 0:
        list.remove(i)
        
print("List without odd numbers is: ", list)
