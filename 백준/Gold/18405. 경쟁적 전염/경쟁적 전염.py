import sys, heapq
input = sys.stdin.readline
DIR = [(1,0), (-1,0), (0,-1),(0,1)]

def dfs(graph, n, s):
    que = []
    for i in range(n):
        for j in range(n):
            if graph[i][j] > 0:
                heapq.heappush(que, (0, graph[i][j], i, j))
    while que:
        t, level, y, x = heapq.heappop(que)
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and graph[ny][nx] == 0 and t < s:
                heapq.heappush(que, (t + 1, graph[y][x], ny, nx))
                graph[ny][nx] = graph[y][x]

    
def main():
    n, k = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(n)]
    s, x, y = map(int, input().split())
    dfs(graph, n, s)
    print(graph[x - 1][y - 1])
    
if __name__ == "__main__":
    main()
