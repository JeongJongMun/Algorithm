import sys
input = sys.stdin.readline
from heapq import heappop, heappush
        
def dijkstra(graph, start):
    visited = [False for _ in range(len(graph) + 1)]
    visited[start] = True
    dist = [1e9 for _ in range(len(graph) + 1)]
    dist[start] = 0
    que = [(0, start)]
    
    while que:
        time, cur = heappop(que)
        for next, weight in graph[cur]:
            next_time = time + weight
            if dist[next] > next_time:
                heappush(que, (next_time, next))
                dist[next] = next_time
                visited[next] = True
    
    cnt, m = 0, 0
    for i in dist:
        if i < 1e9: 
            cnt += 1
            m = max(m, i)
    print(cnt, m)
    
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