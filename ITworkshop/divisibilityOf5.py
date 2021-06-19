ray = []
num = int(input("Enter number of elements: "))
for i in range(num):
    item = int(input("Enter element {0}: ".format(i+1)))
    ray.append(item)
    
print("\nElements from list divisible by 5 are:")
for item in ray:
    if(item > 150):
        break
    if(item % 5 == 0):
        print(item)
