kg = int(input())
stop = 5
compare = []
judgment = 0
i = 1
while kg >= stop:
    if kg % 5 == 0:
        print(int(kg/5))
        judgment += 1
        break
    elif (kg - stop) % 3 == 0:
        compare.append(i+int((kg - stop)/3))
    stop += 5
    i += 1
if compare != [] and judgment == 0:
    print(min(compare))
elif compare == [] and kg % 3 ==0 and judgment == 0:
    print(int(kg/3))
elif compare == [] and judgment == 0:
    print(-1)
