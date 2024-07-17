import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = int(1e9)
for i in range(n - 3):
    for j in range(i + 3, n):
        low, high = i + 1, j - 1
        s1 = arr[i] + arr[j]
        while low < high:
            s2 = arr[low] + arr[high]
            ans = min(ans, abs(s1 - s2))
            
            if s1 > s2:
                low += 1
            elif s1 < s2:
                high -= 1
            else:
                print(0)
                exit()
print(ans)