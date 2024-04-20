import sys
from heapq import heappop, heappush
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, 1), (0, -1)]
INF = int(1e9)

def bfs(graph, n, test_number):
    cost = [[INF] * n for _ in range(n)]
    cost[0][0] = graph[0][0]
    que = [(cost[0][0], 0, 0)] # 현재 x, y, 값
    
    while que:
        v, x, y = heappop(que)
        for dx, dy in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and cost[ny][nx] > graph[ny][nx] + v:
                heappush(que, (graph[ny][nx] + v, nx, ny))
                cost[ny][nx] = graph[ny][nx] + v

    print(f"Problem {test_number}: {cost[n - 1][n - 1]}")
    test_number += 1

def main():
    test_number = 0
    while 1:
        test_number += 1
        n = int(input().strip())
        if n == 0: break
        graph = [list(map(int, input().split())) for _ in range(n)]
        
        bfs(graph, n, test_number)
    
if __name__ == "__main__":
    main()