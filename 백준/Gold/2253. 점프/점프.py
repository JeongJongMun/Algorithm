import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    n, m = map(int, input().split())
    jmax = int((2*n)**0.5 + 1)
    dp = [[INF] * (n + 1) for _ in range(jmax + 1)]
    stone = [int(input()) for _ in range(m)]

    dp[0][1] = 0
    for i in range(2, n + 1):
        if i in stone: continue
        for j in range(1, jmax):
            dp[j][i] = min(dp[j - 1][i - j], dp[j][i - j], dp[j + 1][i - j] ) + 1
    
    ans = min(row[-1] for row in dp)
    print(ans) if ans < INF else print(-1)

if __name__ == "__main__":
    main()