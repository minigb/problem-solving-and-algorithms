import sys
from collections import Counter

def main():
    n = int(input())
    arr = list(map(int, sys.stdin.readline().split()))

    half = n // 2
    counter = Counter(arr)
    if max(counter.values()) > half:
        print(-1)
        return
    
    indices = list(range(n))
    indices = sorted(indices, key = lambda x : arr[x])
    rotated_indices = indices[half:] + indices[:half]

    new_arr = [-1] * n
    for i, j in zip(indices, rotated_indices):
        new_arr[j] = arr[i]
    
    assert not any(elem == -1 for elem in new_arr)
    for a, b in zip(arr, new_arr):
        assert a != b

    print(' '.join(map(str, new_arr)))
        
if __name__=="__main__":
    main()