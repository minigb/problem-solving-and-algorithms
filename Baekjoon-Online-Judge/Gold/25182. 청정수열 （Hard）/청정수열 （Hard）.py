MOD = int(1e9) + 7

def getFactorial(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i
        ret %= MOD

    return ret

def calculateMaxChungsum(n: int):
    total_sum = 0
    local_sum = 0

    for i in range(1, n + 1):
        local_sum += (i * 2) % MOD
        local_sum %= MOD

        total_sum += (local_sum * i) % MOD
        total_sum %= MOD

    return total_sum

def main():
    n = int(input())

    max_sum = calculateMaxChungsum(n)

    factorial = getFactorial(n)
    count = (factorial * factorial) % MOD

    print(max_sum, count)

if __name__=="__main__":
    main()