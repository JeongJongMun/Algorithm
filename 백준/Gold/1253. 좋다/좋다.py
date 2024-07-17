n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ans = 0
for i in range(n):
    low, high = 0, n - 1
    
    while low < high:
        if low == i:
            low += 1
        elif high == i:
            high -= 1
        
        if low == high:
            break

        sum = arr[low] + arr[high]
        if sum == arr[i]:
            ans += 1
            break
        if sum < arr[i]:
            low += 1
        else:
            high -= 1

print(ans)