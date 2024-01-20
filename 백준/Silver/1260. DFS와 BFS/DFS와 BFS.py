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
            for next_node in graph[node]:
                stack.append(next_node)
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
            for next_node in graph[node]:
                queue.append(next_node)
    return answer

v, e, s = map(int, input().split())
graph = [[] for _ in range(v+1)]

for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
for i in range(len(graph)): graph[i].sort(reverse=True)
print(*DFS(graph, s))

for i in range(len(graph)): graph[i].sort()
print(*BFS(graph, s))