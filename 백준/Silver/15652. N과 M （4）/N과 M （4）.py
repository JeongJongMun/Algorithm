n, m = map(int, input().split())

arr = []

def sol(i):
    if len(arr) == m:
        print(' '.join(map(str, arr)))
        return
    for j in range(i, n + 1):
        arr.append(j)
        sol(j)
        arr.pop()
sol(1)