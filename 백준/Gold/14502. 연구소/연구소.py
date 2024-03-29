import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

# 바이러스 전염
def bfs(graph, visited, n, m, i, j):
    que = deque([(i, j)])
    visited[i][j] = True
    while que:
        y, x = que.popleft()
        for dx, dy in DIR:
            nx, ny = dx + x, dy + y
            if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx] and graph[ny][nx] == 0:
                que.append((ny, nx))
                visited[ny][nx] = True
                graph[ny][nx] = 2
    

def main():
    n, m = map(int, input().split())
    # 0은 빈칸, 1은 벽, 2는 바이러스
    graph = [list(map(int, input().split())) for _ in range(n)]
    emptys = [(i, j) for i in range(n) for j in range(m) if graph[i][j] == 0]
    ans = 0
    for walls in combinations(emptys, 3):
        _graph = [row[:] for row in graph]
        for i, j in walls:
            _graph[i][j] = 1

        visited = [[False] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if _graph[i][j] == 2 and not visited[i][j]:
                    bfs(_graph, visited, n, m, i, j)
        
        _ans = 0
        for i in range(n):
            for j in range(m):
                if _graph[i][j] == 0:
                    _ans += 1
        ans = max(ans, _ans)
    
    print(ans)
if __name__ == "__main__":
    main()