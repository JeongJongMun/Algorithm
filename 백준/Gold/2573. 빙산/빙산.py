import sys
input = sys.stdin.readline
from collections import deque

DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def melt(graph, melting, n, m, i, j):
    for i, j in melting:
        if 0 < i - 1 < n and graph[i - 1][j] != 0:
            graph[i - 1][j] -= 1
        if 0 < j - 1 < m and graph[i][j - 1] != 0:
            graph[i][j - 1] -= 1
        if 0 < i + 1 < n and graph[i + 1][j] != 0:
            graph[i + 1][j] -= 1
        if 0 < j + 1 < m and graph[i][j + 1] != 0:
            graph[i][j + 1] -= 1


def bfs(graph, visited, n, m, i, j):
    que = deque([(i, j)])

    while que:
        y, x = que.popleft()
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx] and graph[ny][nx] > 0:
                que.append((ny, nx))
                visited[ny][nx] = True


def main():
    n, m = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(n)]
    year = 0
    
    while True:
        visited = [[False] * m for _ in range(n)]
        cnt = 0
        year += 1
        melting = []
        for i in range(n):
            for j in range(m):
                if graph[i][j] == 0:
                    melting.append((i, j))
        melt(graph, melting, n, m, i, j)
        
        for i in range(n):
            for j in range(m):
                if not visited[i][j] and graph[i][j] > 0:
                    bfs(graph, visited, n, m, i, j)
                    cnt += 1
                    
        if cnt >= 2:
            break
        if year > 1000:
            break
                    
    print(year if year < 1000 else 0)


if __name__ == "__main__":
    main()