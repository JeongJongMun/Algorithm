import math

def prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            return False
    return True

n = int(input())
li = list(map(int, input().split()))

cnt = 0
for elem in li:
    if prime(elem):
        cnt += 1

print(cnt)