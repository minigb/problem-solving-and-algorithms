import math

def lcm2(a, b):
    return a * b // math.gcd(a, b)

def lcm(a, b, c):
    return lcm2(lcm2(a, b), c)

t = int(input())
while t:
    t -= 1
    n = int(input())

    if n % 2 == 0:
        print(max(lcm(n, n - 1, n - 3), lcm(n - 1, n - 2, n - 3)))
    else:
        print(lcm(n, n - 1,n - 2))