from collections import defaultdict

q = int(input())

height = defaultdict(int)
while q:
    q -= 1
    query_num, index = input().split()
    query_num = int(query_num)
    index = int(index)

    if query_num == 1:
        max_h = 0
        for i in range(index, index + 4):
            max_h = max(max_h, height[i])
        for i in range(index, index + 4):
            height[i] = max_h + 1
    elif query_num == 2:
        height[index] += 4
    else:
        print(height[index])
