import math
from collections import defaultdict

prime_numbers = []

def getPrimeNumbers(max_num) -> None:
    isPrime = [True] * (max_num + 1)
    isPrime[1] = False

    for i in range(2, max_num + 1):
        if isPrime[i]:
            prime_numbers.append(i)
            for j in range(i, max_num + 1, i):
                isPrime[j] = False

def primeFactorization(number) -> dict:
    primes = defaultdict(int)
    for prime in prime_numbers:
        if (number % prime == 0):
            count = 0
            while number % prime == 0:
                count += 1
                number //= prime
            primes[prime] = count
    if number > 1:
        primes[number] = 1

    return primes

def getLevel(primes: dict) -> int:
    count_sum = sum(list(primes.values()))
    return count_sum

def getValue(primes: dict) -> int:
    ret = 1
    for prime, count in primes.items():
        for _ in range(count):
            ret *= prime
    return ret

def reduceLevel(primes: dict):
    min_prime = min(list(primes.keys()))
    primes[min_prime] -= 1
    if primes[min_prime] == 0:
        del primes[min_prime]

def main():
    a, b = input().split()
    a, b = int(a), int(b)
    getPrimeNumbers(int(math.sqrt(max(a, b))))

    a_primes = primeFactorization(a)
    b_primes = primeFactorization(b)

    a_level = getLevel(a_primes)
    b_level = getLevel(b_primes)

    while a_level > b_level:
        reduceLevel(a_primes)
        a_level -= 1
    while (b_level > a_level):
        reduceLevel(b_primes)
        b_level -= 1

    while getValue(a_primes) != getValue(b_primes):
        reduceLevel(a_primes)
        reduceLevel(b_primes)

    print(getValue(a_primes))
    


if __name__=='__main__':
    main()