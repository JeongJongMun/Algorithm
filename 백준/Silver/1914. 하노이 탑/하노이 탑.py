def hanoi(n: int, s: int, e: int):
    if (n > 20):
        return
    if n > 1:
        hanoi(n-1, s, 6-s-e)
    
    print(s, e)
    if n > 1:
        hanoi(n-1, 6-s-e, e)
        
n = int(input())
print(2**n - 1)
hanoi(n, 1, 3)