import sys
input = sys.stdin.readline
    
def main():
    t = int(input().strip())
    for _ in range(t):
        n = int(input())
        coin = list(map(int, input().split()))
        goal = int(input().strip())
        dp = [0] * (goal + 1)
        dp[0] = 1
        for i in range(n):
            for j in range(coin[i], goal + 1):
                dp[j] += dp[j - coin[i]]

        print(dp[goal])

if __name__ == "__main__":
    main()