input = int(input())
cnt, n = 0, input
while 1:
    cnt += 1
    if n < 10: nn = n*11
    else: nn = n%10 + n//10
    n = n%10*10 + nn%10
    if n == input: break
print(cnt)