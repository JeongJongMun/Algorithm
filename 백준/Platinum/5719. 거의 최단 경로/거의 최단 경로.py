import sys
from heapq import heappop, heappush
from collections import deque
INF = int(1e9)
input = sys.stdin.readline

def dijkstra(_graph):
    hq = [(0, s)]
    distances = [INF] * n
    distances[s] = 0
    
    while hq:
        dist, node = heappop(hq)
        for next_node, cost in _graph[node]:
            if edges[node][next_node]: continue
            
            next_cost = dist + cost
            if distances[next_node] > next_cost:
                distances[next_node] = next_cost
                heappush(hq, (next_cost, next_node))

    return distances

def bfs(_graph, distances):
    queue = deque([d])
    
    while queue:
        prev_node = queue.popleft()
        for next_node, cost in _graph[prev_node]:
            if distances[prev_node] == distances[next_node] + cost and not edges[next_node][prev_node]:
                edges[next_node][prev_node] = True
                queue.append(next_node)

while True:
    n, m = map(int, input().split())
    if not n and not m: break
    s, d = map(int, input().split())

    graph = [[] for _ in range(n)]
    reversed_graph = [[] for _ in range(n)]
    edges = [[False] * n for _ in range(n)]
    for i in range(m):
        u, v, p = map(int, input().split())
        graph[u].append((v, p))
        reversed_graph[v].append((u, p))
    
    distances = dijkstra(graph)
    bfs(reversed_graph, distances)

    ans = dijkstra(graph)[d]
    print(ans if ans < INF else -1)
