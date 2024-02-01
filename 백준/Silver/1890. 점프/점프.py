import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    arr = [list(map(int, input().split())) for _ in range(n)]
    # print(*arr, sep='\n')

    dp = [[0] * n for _ in range(n)]
    dp[0][0] = 1
    for i in range(n):
        for j in range(n):
            num = arr[i][j]
            if num == 0: continue
            if i + num < n:
                dp[i + num][j] += dp[i][j]
            if j + num < n:
                dp[i][j + num] += dp[i][j]
                
    # print(*dp, sep='\n')
    print(dp[n - 1][n - 1])


if __name__ == "__main__":
    main()