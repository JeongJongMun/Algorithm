import sys
from heapq import heappush, heappop
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, end, isOneToOne = True):
    while hq:
        dist, node = heappop(hq)
        if isOneToOne and node == end:
            answer[start] += dist
            return
        
        for next_node, cost in graph[node]:
            next_cost = dist + cost
            if distances[next_node] > next_cost:
                distances[next_node] = next_cost
                heappush(hq, (next_cost, next_node))

n, m, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

answer = [0] * (n + 1)
for child in range(1, n + 1):
    distances = [INF] * (n + 1)
    hq = [(0, child)]
    dijkstra(child, x)


distances = [INF] * (n + 1)
hq = [(0, x)]
dijkstra(x, 0, False)

for i in range(n + 1):
    answer[i] += distances[i]
    
print(max(answer[1:]))