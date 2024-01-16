n, m = map(int, input().split())

width = [0, n]
length = [0, m]

k = int(input())
for i in range(k):
    wl, num = map(int, input().split())
    width.append(num) if wl else length.append(num)
    
width.sort()
length.sort()

w_max = 0
l_max = 0
for i in range(len(width) - 1):
    w_max = max(w_max, width[i + 1] - width[i])

for i in range(len(length) - 1):
    l_max = max(l_max, length[i + 1] - length[i])
    
print(w_max * l_max)