import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, visited, start):
    queue = deque([start])
    cnt = -1
    while queue:
        node = queue.popleft()
        if visited[node] == False:
            visited[node] = True
            cnt += 1
            queue.extend(graph[node])
    return cnt

def main():
    v = int(input())
    e = int(input())
    graph = [[] for _ in range(v+1)]
    visited = [False for _ in range(v+1)]

    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    print(bfs(graph, visited, 1))
    
if __name__ == '__main__':
    main()