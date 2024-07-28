import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def dfs(sy, sx):
    if sy == m - 1 and sx == n - 1:
        return 1
    if dp[sy][sx] != -1:
        return dp[sy][sx]
    
    cnt = 0
    for dx, dy in DIR:
        nx, ny = sx + dx, sy + dy
        if 0 <= ny < m and 0 <= nx < n and graph[sy][sx] > graph[ny][nx]:
            cnt += dfs(ny, nx)

    dp[sy][sx] = cnt
    return dp[sy][sx]
    
# 세로, 가로
m, n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]
dp = [[-1] * n for _ in range(m)]

print(dfs(0, 0))