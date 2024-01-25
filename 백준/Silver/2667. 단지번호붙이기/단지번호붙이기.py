import sys
from collections import deque
input = sys.stdin.readline
DIR = [(1,0), (-1,0), (0,-1),(0,1)]

def dfs(graph, visited, si, sj, n):
    que = deque([(si, sj)])
    visited[si][sj] = 1
    cnt = 0
    while que:
        y, x = que.popleft()
        cnt += 1
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and not visited[ny][nx] and graph[ny][nx] == 1:
                que.append((ny, nx))
                visited[ny][nx] = 1
    return cnt
    
def main():
    n = int(input().strip())
    graph = [list(map(int, input().strip())) for _ in range(n)]
    visited = [[0] * n for _ in range(n)]
    ans = 0
    li = []
    for i in range(n):
        for j in range(n):
            if graph[i][j] and not visited[i][j]:
                ans = dfs(graph, visited, i, j, n)
                li.append(ans)
    li.sort()
    print(len(li))
    print(*li, sep='\n')
        
if __name__ == "__main__":
    main()