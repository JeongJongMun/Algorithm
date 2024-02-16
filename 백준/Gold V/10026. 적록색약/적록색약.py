import sys
from collections import deque
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

# 적록색약: R과G가 같음 red-green blindness
# 적록색약X: R G B 모두 다름
def bfs(graph, visited, n, i, j, isRGB : bool):
    que = deque([(i, j)])
    visited[i][j] = True
    if isRGB:
        color = ['R', 'G'] if graph[i][j] == 'R' or graph[i][j] == 'G' else ['B']
    else:
        color = [graph[i][j]]
    
    while que:
        x, y = que.popleft()
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny] in color:
                visited[nx][ny] = True
                que.append((nx, ny))
    
    
def main():
    n = int(input().strip())
    # rgb = red-green blindness
    _rgb = [list(map(str, input().strip())) for _ in range(n)]
    rgb = _rgb.copy()
    
    _visited = [[False] * n for _ in range(n)]
    visited = [[False] * n for _ in range(n)]
    
    a, b = 0, 0
    for i in range(n):
        for j in range(n):
            if not _visited[i][j]:
                bfs(_rgb, _visited, n, i ,j, False)
                a += 1
            if not visited[i][j]:
                bfs(rgb, visited, n, i, j, True)
                b += 1
 
    print(a, b)
    
if __name__ == "__main__":
    main()