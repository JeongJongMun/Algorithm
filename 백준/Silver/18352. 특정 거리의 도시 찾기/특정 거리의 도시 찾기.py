import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9
    
def bfs(graph, k, start):
    visited = [False] * (len(graph) + 1)
    dist = [INF] * (len(graph) + 1)
    dist[start] = 0
    que = deque([start])
    
    while que:
        node = que.popleft()
        visited[node] = True
        for next_node in graph[node]:
            if not visited[next_node]:
                que.append(next_node)
                dist[next_node] = min(dist[next_node], dist[node] + 1)
    
    return [idx for idx, cost in enumerate(dist) if cost == k] or [-1]
                    
def main():
    v, e, k, x = map(int, input().strip().split())
    graph = [[] for _  in range(v + 1)]
    for _ in range(e):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
    ans = bfs(graph, k, x)
    for idx in ans: print(idx)
        
    # ans = [(idx, cost) for idx, cost in enumerate(dist) if cost == k]

    # if ans:
    #     for idx, _ in ans:
    #         print(idx)
    # else: print(-1)
            
if __name__ == '__main__':
    main()