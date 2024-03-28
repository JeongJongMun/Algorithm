import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    coins = []
    dp = [0] * (k + 1)
    for _ in range(n):
        c = int(input().strip())
        coins.append(c)

    dp[0] = 1
    for i in coins:
        for j in range(i, k + 1):
            dp[j] += dp[j - i]
    print(dp[-1])
if __name__ == "__main__":
    main()