save_dict = {}
def get(k):
    # return k*k*(k+1)//2 - k*(k+1)*(2*k+1)//6 + 1
    if k in save_dict.keys():
        return save_dict[k]
    result = (k + 1) * k* (k + 1) // 2 - k * (k + 1) * (2 * k + 1) // 6
    save_dict[k] = result
    return result

n = input()
s = input()

count_vec = []
count = 0
for c in s:
    if c == '2':
        count += 1
    else:
        if count != 0:
            count_vec.append(count)
            count = 0


if count != 0:
    count_vec.append(count)
    count = 0


ans = 0
for count in count_vec:
    ans += get(count)

print(ans)
