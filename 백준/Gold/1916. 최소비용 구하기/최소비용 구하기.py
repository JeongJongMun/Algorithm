import sys, heapq
input = sys.stdin.readline
INF = 1e9

def Dijkstra(graph, start, end):
    visited = [0] * len(graph)
    dist = [INF] * len(graph)
    dist[start] = 0
    pq = [(0, start)]
    
    while pq:
        cost, node = heapq.heappop(pq)
        if node == end: break
        visited[node] = 1
        for next_cost, next_node in graph[node]:
            if dist[next_node] > cost + next_cost and not visited[next_node]:
                dist[next_node] = cost + next_cost
                heapq.heappush(pq, (dist[next_node], next_node))
                
    return dist[end]
        

def main():
    v = int(input())
    graph = [[] for _ in range(v + 1)]
    
    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        graph[a].append((c, b))
    start, end = map(int, input().split())
    
    print(Dijkstra(graph, start, end))
    
if __name__ == '__main__':
    main()