import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = 1e9

def dijkstra(graph, n):
    hq = [(0, 1)]
    distance = [1e9] * (n + 1)
    distance[1] = 0

    while hq:
        dist, cur = heappop(hq)
        for weight, next_node in graph[cur]:
            next_dist = dist + weight
            if (next_dist < distance[next_node]):
                distance[next_node] = next_dist
                heappush(hq, (next_dist, next_node))
    print(distance[n])
    
def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        s, e, w = map(int, input().split())
        graph[s].append((w, e))
        graph[e].append((w, s))
    dijkstra(graph, n)
        
if __name__ == '__main__':
    main()