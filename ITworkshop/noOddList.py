ray = []
for i in range(20):
    ray.append(i + 1)
print(ray)

for num in ray:
    if num % 2 != 0:
        ray.remove(num)
    
print(ray)
