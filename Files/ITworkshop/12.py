list = []
sum = 0
num = int(input("Enter a number: "))
for i in range(1, num):
    list.append(i)
print("The list is:", list)

for n in range(1, num):
    if n > 1:
        for i in range(2, n):
            if(n % i) == 0:
                break;
        else:
            list.remove(n)
        
print("List without prime numbers is:", list)
