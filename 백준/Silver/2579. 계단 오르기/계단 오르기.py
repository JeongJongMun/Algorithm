import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    arr = [int(input().strip()) for _ in range(n)]
    if n == 1:
        print(arr[0])
        quit()
    dp = [0] * n
    dp[0] = arr[0]
    dp[1] = arr[0] + arr[1]
    for i in range(2, n):
        dp[i] = max(arr[i - 1] + dp[i - 3], dp[i - 2]) + arr[i]
    print(dp[-1])
if __name__ == "__main__":
    main()