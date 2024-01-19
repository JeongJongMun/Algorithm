import sys
import heapq
input = sys.stdin.readline

def prim(graph, start):
    n, ans = len(graph), 0
    visited, pq = [False] * n, [[0, start]]

    while pq:
        cost, node = heapq.heappop(pq)
        if visited[node]: continue
        visited[node] = True
        ans += cost
        for ncost, nnode in graph[node]: heapq.heappush(pq, [ncost, nnode]) if visited[nnode] == False else None
    return ans        

def main():
    v, e = map(int, input().split())
    graph = [[] for _ in range(v+1)]
    for _ in range(e):
        start, end, cost = map(int, input().split())
        graph[start].append([cost, end])
        graph[end].append([cost, start])
    ans = prim(graph, 1)
    print(ans)
    
if __name__ == '__main__':
    main()