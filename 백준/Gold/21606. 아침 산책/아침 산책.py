import sys
from collections import deque
input = sys.stdin.readline

def walk(graph, inside, visited, start):
    _visited = visited.copy()
    que = deque([start])
    cnt = 0
    while que:
        node = que.popleft()
        for next_node in graph[node]:
            if not _visited[next_node] and not inside[next_node]:
                que.append(next_node)
                _visited[next_node] = 1
            elif inside[next_node] and next_node != start:
                cnt += 1
    return cnt
                  
def main():
    v = int(input().strip())
    inside = list(map(int, input().strip()))
    inside = [0] + inside
    graph = [[] for _ in range(v + 1)]
    visited = [1 if inside[i] else 0 for i in range(v+1)]
    for _ in range(v - 1):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
        graph[b].append(a)

    flag = True
    for i in range(2, len(graph) -1):
        if len(graph[i]) != 2:
            flag = False
            break
    if flag:
        print(max(0, (sum(inside) - 1) * 2))
        exit()

    ans = 0
    for start in range(1, v + 1):
        if visited[start]:
            ans += walk(graph, inside, visited, start)
    
    print(ans)
    
if __name__ == '__main__':
    main()