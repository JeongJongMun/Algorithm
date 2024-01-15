from typing import List
import math

def eratos(n: int)-> List:
    prime = [True for i in range(n+1)]
    
    for i in range(2, int(math.sqrt(n))):
        if prime[i]:
            for j in range(i*i, n+1, i):
                prime[j] = False
    
    return [i for i in range(n+1) if prime[i]]

primes = eratos(10000)
T = int(input())
n = [int(input()) for i in range(T)]
for elem in n:
    p1 = p2 = elem // 2
    while 1:
        if p1 in primes and p2 in primes:
            print(p1, p2)
            break
        else:
            p1 -= 1
            p2 += 1