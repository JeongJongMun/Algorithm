n, arr = int(input()), list(map(int, input().split()))
dp = [0] * 1001
for s in arr: dp[s] = max(dp[:s]) + 1
print(max(dp))