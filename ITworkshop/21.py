ray = []
num = int(input("Enter number of elements: "))
for i in range(num):
    item = int(input("Enter element {0}: ".format(i+1)))
    ray.append(item)
  
start = num - 1
stop = -1
step = -1
for i in range(start, stop, step):
    print(ray[i], end = ' ')
print("")
