import sys
sys.setrecursionlimit(10**6)
a, b, c = map(int, input().split())

def mul(a, b, c):
    if b == 1:
        return a % c

    return (mul(a, b//2, c)**2) % c if b % 2 == 0 else ((mul(a, b//2, c)**2)*a) % c

print(mul(a, b, c))