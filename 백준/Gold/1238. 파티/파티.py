import sys
from heapq import heappush, heappop
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(_graph, start):
    n = len(_graph)
    distances = [INF] * (n + 1)
    distances[x] = 0
    hq = [(0, start)]

    while hq:
        dist, node = heappop(hq)
        for next_node, cost in _graph[node]:
            next_cost = dist + cost
            if distances[next_node] > next_cost:
                distances[next_node] = next_cost
                heappush(hq, (next_cost, next_node))
    
    for i in range(n):
        answer[i] += distances[i]

n, m, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

answer = [0] * (n + 1)

dijkstra(graph, x)

reversed_graph = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    for b, c in graph[i]:
        reversed_graph[b].append((i, c))

dijkstra(reversed_graph, x)

print(max(answer[1:]))