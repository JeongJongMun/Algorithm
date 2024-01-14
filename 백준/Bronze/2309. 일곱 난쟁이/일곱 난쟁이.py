li = [int(input()) for i in range(9)]
sum = sum(li)
li = sorted(li)

for i in range(9):
    for j in range(i+1, 9):
        if sum - li[i] - li[j] == 100:
            print()
            for k in range(9):
                if k != i and k != j:
                    print(li[k])
            exit()