n = int(input())

cow = []
li = [0 for i in range(1001)]

for i in range(n):
    s, e = map(int, input().split())
    cow.append([s, e])
    for j in range(s, e):
        li[j] += 1

ans = 0
for s, e in cow:
    temp = 0
    for idx, val in enumerate(li):
        if s <= idx < e:
            if val - 1 > 0:
                temp += 1
        elif val > 0:
            temp += 1
    ans = max(ans, temp)
    
print(ans)