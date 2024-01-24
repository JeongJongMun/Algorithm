import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
INF = 1e9
# 위 아래 왼쪽 오른쪽 앞 뒤 - xyz
dir = [(0, 0, 1), (0, 0, -1), (-1, 0, 0), (1, 0, 0), (0, 1, 0), (0, -1, 0)]
cnt = goal = 0

def bfs(tomato, m, n, h):
    que = deque()
    global cnt

    for k in range(h):
        for j in range(n):
            for i in range(m):
                if tomato[k][j][i] == 1:
                    que.append((i,j,k))
    
    while que:
        x, y, z = que.popleft()
        for dx, dy, dz in dir:
            nx, ny, nz = x + dx, y + dy, z + dz
            if nx >= 0 and nx < m and ny >= 0 and ny < n and nz >= 0 and nz < h and tomato[nz][ny][nx] == 0:
                que.append((nx, ny, nz))
                tomato[nz][ny][nx] = tomato[z][y][x] + 1
                cnt += 1

def main():
    m, n, h = map(int, input().split())
    tomato = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
        
    global cnt, goal
    goal = m * n * h
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if tomato[i][j][k] == 1: cnt += 1
                elif tomato[i][j][k] == -1: goal -= 1
    bfs(tomato, m, n, h)
    print(max(max(map(max, mat)) for mat in tomato) - 1) if cnt == goal else print(-1)

if __name__ == "__main__":
    main()