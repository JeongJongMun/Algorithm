import sys
input = sys.stdin.readline
from heapq import heappop, heappush
INF = int(1e9)
        
def dijkstra(graph, start):
    dist = [INF for _ in range(len(graph) + 1)]
    dist[start] = 0
    que = [(0, start)]
    
    while que:
        time, cur = heappop(que)
        for next, weight in graph[cur]:
            next_time = time + weight
            if dist[next] > next_time:
                heappush(que, (next_time, next))
                dist[next] = next_time
                
    infected_cnt = sum(list(1 for i in dist if i < INF))
    last_infected = max(i for i in dist if i < INF)
    print(infected_cnt, last_infected)
    
def main():
    for _ in range(int(input().strip())):
        n, d, c = map(int, input().split())
        graph = [[] for _ in range(n + 1)]
        for i in range(d):
            a, b, s = map(int, input().split())
            graph[b].append((a, s))
        dijkstra(graph, c)
            
if __name__ == "__main__":
    main()