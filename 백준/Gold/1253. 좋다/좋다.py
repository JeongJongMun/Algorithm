import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = 0
for i in range(n):
    low, high = 0, n - 1
    
    while low != high:
        if low == i:
            low += 1
            continue
        elif high == i:
            high -= 1
            continue
        
        sum = arr[low] + arr[high]
        if sum < arr[i]:
            low += 1
        elif sum > arr[i]:
            high -= 1
        else:
            ans += 1
            break

print(ans)