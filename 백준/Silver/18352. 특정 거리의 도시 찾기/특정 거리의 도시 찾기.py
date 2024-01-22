import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9
    
def bfs(graph, visited, dist, start):
    que = deque([start])
    while que:
        node= que.popleft()
        visited[node] = True
        for next_node in graph[node]:
            if not visited[next_node]:
                que.append(next_node)
                dist[next_node] = min(dist[next_node], dist[node] + 1)
                    
def main():
    v, e, k, x = map(int, input().strip().split())
    graph = [[] for _  in range(v + 1)]
    visited = [False for _ in range(v + 1)]
    dist = [INF for _ in range(v + 1)]
    dist[x] = 0
    for _ in range(e):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
    bfs(graph, visited, dist, x)    
    ans = [(idx, cost) for idx, cost in enumerate(dist) if cost == k]

    if ans:
        for idx, _ in ans:
            print(idx)
    else: print(-1)
            
if __name__ == '__main__':
    main()