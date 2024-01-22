import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9

def topological_sort(graph, indegree):
    visited = [False] * len(graph)
    que, result = deque(), []
    
    for idx, cost in enumerate(indegree):
        if cost == 0 and idx != 0:
            que.append(idx)
            visited[idx] = True
                        
    while que:
        node = que.popleft()
        result += [node]
        for next_node in graph[node]:
            indegree[next_node] -= 1
            if indegree[next_node] == 0:
                que.append(next_node)
                visited[next_node] = True
        # for idx, cost in enumerate(indegree):
        #     if cost == 0 and not visited[idx] and idx != 0:
        #         que.append(idx)
        #         visited[idx] = True
                

    return result
                  
def main():
    v, e = map(int, input().split())
    graph = [[] for _ in range(v + 1)]
    indegree = [0] * (v + 1)
    
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a] += [b]
        indegree[b] += 1

    answer = topological_sort(graph, indegree)
    print(*answer)
    

        
if __name__ == '__main__':
    main()