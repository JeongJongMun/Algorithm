input = int(input())
cnt = 0
n = input
while 1:
    cnt += 1

    if n < 10:
        nn = n + n*10
    else:
        nn = n % 10 + n // 10
    n = (n % 10)*10 + nn % 10

    if n == input:
        break
 
print(cnt)
'''
1 -> 0 + 1 -> 11 ->
'''