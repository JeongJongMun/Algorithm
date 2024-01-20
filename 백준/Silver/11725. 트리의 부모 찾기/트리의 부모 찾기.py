import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, visited, parent, start):
    queue = deque([start])
    while queue:
        node = queue.popleft()
        visited[node] = True 
        for next_node in graph[node]:
            if not visited[next_node]: 
                queue.append(next_node)
                parent[next_node] = node
                    
def main():
    v = int(input().strip())
    graph = [[] for _ in range(v+1)]
    visited = [False for _ in range(v+1)]
    parent = [i for i in range(v+1)]

    for _ in range(v-1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    bfs(graph, visited, parent, 1)
    print(*parent[2:], sep='\n')
    
if __name__ == '__main__':
    main()