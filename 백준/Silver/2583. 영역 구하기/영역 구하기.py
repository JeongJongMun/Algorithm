import sys
from collections import deque
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def bfs(graph, visited, m, n, i, j):
    que = deque([(i, j)])
    visited[i][j] = True
    size = 1
    
    while que:
        x, y = que.popleft()
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny] == 0:
                que.append((nx, ny))
                visited[nx][ny] = True
                size += 1
    return size

def main():
    m, n, k = map(int, input().split())
    graph = [[0] * n for _ in range(m)]
    visited = [[False] * n for _ in range(m)]

    for _ in range(k):
        sj, si, ej, ei = map(int, input().split())
        for i in range(si, ei):
            for j in range(sj, ej):
                graph[i][j] = 1
                
    width = []
    for i in range(m):
        for j in range(n):
            if graph[i][j] == 0 and not visited[i][j]:
                s = bfs(graph, visited, m, n, i, j)
                width.append(s)
    
    print(len(width))
    print(*sorted(width))    
                
if __name__ == '__main__':
    main()