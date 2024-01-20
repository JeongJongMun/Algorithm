import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, visited, start):
    queue = deque([start])
    if visited[start] == True: return False
    while queue:
        node = queue.popleft()
        if visited[node] == False:
            visited[node] = True
            queue.extend(sorted(graph[node]))
    return True

def main():
    v, e = map(int, input().split())
    graph = [[] for _ in range(v+1)]
    visited = [False for _ in range(v+1)]

    cnt = 0
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    for i in range(1, v+1):
        cnt += 1 if bfs(graph, visited, i) else 0
    print(cnt)
    
if __name__ == '__main__':
    main()