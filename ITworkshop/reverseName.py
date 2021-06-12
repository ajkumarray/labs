ray = []
ray2 = []
num = int(input("Enter number of elements: "))

for i in range(num):
    item = input()
    ray.append(item)
print(ray)

for item in ray:
    ray2.append(item[::-1])
print(ray2)
