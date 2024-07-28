import sys
input = sys.stdin.readline

for _  in range(int(input())):
    n = int(input())
    coins = list(map(int, input().split()))
    goal = int(input())
    
    dp = [0] * (goal + 1)
    dp[0] = 1

    for i in range(n):
        for j in range(coins[i], goal + 1):
            dp[j] += dp[j - coins[i]]

    print(dp[goal])