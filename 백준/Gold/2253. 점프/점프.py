import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    n, m = map(int, input().split())
    jmax = int((2*n)**0.5 + 1)
    dp = [[INF] * (n + 1) for _ in range(jmax)]
    
    for _ in range(m):
        x = int(input())
        for i in range(jmax):
            dp[i][x] = -1

    dp[0][1] = 0
    dj = [-1, 0, 1]
    for i in range(2, n + 1):
        for j in range(1, jmax):
            if dp[j][i] == -1: continue
            for d in dj:
                jump = max(0, min(jmax - 1, j + d))
                if dp[jump][i - j] == -1: continue
                dp[j][i] = min(dp[j][i], dp[jump][i - j] + 1)
    
    ans = min(row[-1] for row in dp)
    print(ans) if ans != INF else print(-1)

    
if __name__ == "__main__":
    main()