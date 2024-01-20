import sys
from typing import List
from collections import deque
input = sys.stdin.readline

def DFS(graph: List, start: int) -> List:
    visited = [False for _ in range(len(graph))]
    stack, answer = [start], []
    while stack:
        node = stack.pop()
        if visited[node] == False:
            visited[node] = True
            answer.append(node)
            stack.extend(reversed(sorted(graph[node])))
    return answer


def BFS(graph: List, start: int) -> List:
    visited = [False for _ in range(len(graph))]
    queue, answer = deque(), []
    queue.append(start)
    while queue:
        node = queue.popleft()
        if visited[node] == False:
            visited[node] = True
            answer.append(node)
            queue.extend(sorted(graph[node]))
    return answer

v, e, s = map(int, input().split())
graph = [[] for _ in range(v+1)]

for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
print(*DFS(graph, s))
print(*BFS(graph, s))