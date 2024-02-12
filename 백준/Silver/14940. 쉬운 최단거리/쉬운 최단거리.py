import sys
from collections import deque
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def bfs(arr, dist, n, m, i, j):
    visited = [[False] * m for _ in range(n)]
    visited[i][j] = True
    que = deque([(0, i, j)])
    while que:
        cost, x, y = que.popleft()
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and arr[nx][ny] != 0:
                dist[nx][ny] = cost + 1
                visited[nx][ny] = True
                que.append((cost + 1, nx, ny))

    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1 and dist[i][j] == 0:
                print(-1, end=" ")
            else:
                print(dist[i][j], end=" ")
        print()

def main():
    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]
    dist = [[0] * m for _ in range(n)]
    target = [(i, j) for j in range(m) for i in range(n) if arr[i][j] == 2]
    
    bfs(arr, dist, n, m, target[0][0], target[0][1])

if __name__ == "__main__":
    main()