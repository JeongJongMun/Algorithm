n = int(input())

def IsHan(n: int) -> bool:
    gap = int(str(n)[1]) - int(str(n)[0])
    for i in range(1, len(str(n))):
        if int(str(n)[i]) - int(str(n)[i - 1]) != gap:
            return False
    return True

cnt = 0
for i in range(1, n + 1):
    cnt += 1 if i < 10 else 1 if IsHan(i) else 0

print(cnt)