import sys
input = sys.stdin.readline
from heapq import heappop, heappush

def bfs(jump):
    graph = [-1] * 101
    graph[1] = 0
    # visited = [False] * 101
    que = [(0, 1)]
    
    while que:
        cost, node = heappop(que)
        for i in range(1, 7):
            n_node = node + i
            if n_node <= 100 and graph[n_node] <= graph[node] and graph[n_node] == -1:
                if n_node in jump:
                    heappush(que, (cost + 1, jump[n_node]))
                    graph[jump[n_node]] = cost + 1
                    # visited[jump[n_node]] = True
                else:
                    heappush(que, (cost + 1, n_node))
                graph[n_node] = cost + 1
                # visited[n_node] = True
            
    return graph[100]

def main():
    n, m = map(int, input().split())
    jump = {}
    for _ in range(n + m):
        x, y = map(int, input().split())
        jump[x] = y
  
    print(bfs(jump))
    
if __name__ == "__main__":
    main()