n, m = map(int, input().split())
x, y = [0, n], [0, m]
for _ in range(int(input())):
    xy, num = map(int, input().split())
    x.append(num) if xy else y.append(num)
x.sort()
y.sort()
w_m = 0
l_m = 0
w_m = max([max(w_m, x[i + 1] - x[i]) for i in range(len(x) - 1)])
l_m = max([max(l_m, y[i + 1] - y[i]) for i in range(len(y) - 1)])
print(w_m * l_m)