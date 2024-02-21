import sys
input = sys.stdin.readline

def main():
    dp = [0] * 101
    dp[0] = dp[1] = dp[2] = dp[3] = 1
    for i in range(4, 101):
        dp[i] = dp[i - 2] + dp[i - 3]
    for _ in range(int(input().strip())):
        print(dp[int(input().strip())])

if __name__ == "__main__":
    main()