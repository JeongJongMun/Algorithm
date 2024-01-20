import sys
from collections import deque
input = sys.stdin.readline
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(graph, cnt, i, j):
    queue = deque([(i,j)])
    while queue:
        x, y = queue.popleft()
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if nx >= 0 and nx < len(graph) and ny >= 0 and ny < len(graph[0]) and graph[nx][ny] != 0 and cnt[nx][ny] == 0:
                queue.append((nx, ny))
                cnt[nx][ny] = cnt[x][y] + 1
    return True
                    
def main():
    n, m = map(int, input().split())
    graph = [list(map(int, input().strip())) for _ in range(n)]
    cnt = [[0 for _ in range(m)] for _ in range(n)]
    cnt[0][0] = 1
    bfs(graph, cnt, 0, 0)
    print(cnt[n-1][m-1])

if __name__ == '__main__':
    main()