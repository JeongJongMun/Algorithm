import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    dp = [0] * (n + 3)
    dp[0] = dp[3] = dp[5] = 1
    for i in range(6, n + 1):
        a = dp[i - 3] if dp[i - 3] else 1e4
        b = dp[i - 5] if dp[i - 5] else 1e4
        dp[i] = min(a, b) + 1
    print(dp[n] if dp[n] and dp[n] < 10000 else -1)

if __name__ == "__main__":
    main()
