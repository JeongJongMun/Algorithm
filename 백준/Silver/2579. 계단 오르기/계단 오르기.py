n = int(input())
arr = [int(input()) for _ in range(n)]
if n == 1:
    print(arr[0])
    exit()
elif n == 0:
    print(0)
    exit()
    
dp = [0] * n
dp[0] = arr[0]
dp[1] = arr[0] + arr[1]
for i in range(2, len(dp)):
    dp[i] = arr[i] + max(dp[i - 3] + arr[i - 1], dp[i - 2])

print(dp[-1])