n, m = map(int, input().split())
x = [0, n]
y = [0, m]
for i in range(int(input())):
    xy, num = map(int, input().split())
    x.append(num) if xy else y.append(num)
x.sort()
y.sort()
w_max = 0
l_max = 0
w_max = max([max(w_max, x[i + 1] - x[i]) for i in range(len(x) - 1)])
l_max = max([max(l_max, y[i + 1] - y[i]) for i in range(len(y) - 1)])
print(w_max * l_max)