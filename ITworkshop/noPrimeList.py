def isPrime(num):
    flag = True
    if num > 1:
        for i in range(2, num):
            if(num % i) == 0:
                flag = False
                break
    return flag


ray = []
for i in range(20):
    ray.append(i + 1)
print(ray)
for num in ray:
    if isPrime(num):
        ray.remove(num)
print(ray)
