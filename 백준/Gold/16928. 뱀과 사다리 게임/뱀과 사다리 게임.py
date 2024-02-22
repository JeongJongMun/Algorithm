import sys
input = sys.stdin.readline
from heapq import heappop, heappush

def bfs(ladder, snake):
    graph = [0] * 101
    visited = [False] * 101
    que = [(0, 1)]
    
    while que:
        cost, node = heappop(que)
        for i in range(1, 7):
            n_node = node + i
            if 0 <= n_node <= 100 and graph[n_node] <= graph[node] and not visited[n_node]:
                if n_node in ladder:
                    j_node = ladder[n_node]
                elif n_node in snake:
                    j_node = snake[n_node]
                else:
                    j_node = False
                    heappush(que, (cost + 1, n_node))
                    
                if j_node:
                    heappush(que, (cost + 1, j_node))
                    graph[j_node] = cost + 1
                    visited[j_node] = True
                graph[n_node] = cost + 1
                visited[n_node] = True
            
    return graph[100]

def main():
    n, m = map(int, input().split())
    ladder, snake = {}, {}
    for i in range(n):
        x, y = map(int, input().split())
        ladder[x] = y
    
    for i in range(m):
        u, v = map (int, input().split())
        snake[u] = v
    
    print(bfs(ladder, snake))
    
if __name__ == "__main__":
    main()