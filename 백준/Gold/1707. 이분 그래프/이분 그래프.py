import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, visited, color, start):
    queue = deque([start])
    while queue:
        node = queue.popleft()
        visited[node] = True 
        for next_node in graph[node]:
            if color[next_node] == color[node]: return False
            color[next_node] = 0 if color[node] else 1
            if not visited[next_node]:
                queue.append(next_node)
    
    return True
                    
def main():
    for _ in range(int(input().strip())):
        v, e = map(int, input().split())
    
        graph = [[] for _ in range(v+1)]
        visited = [False for _ in range(v+1)]
        color = [-1 for _ in range(v+1)]

        for _ in range(e):
            a, b = map(int, input().split())
            graph[a].append(b)
            graph[b].append(a)
        
        flag = True    
        for i in range(1, v+1):
            color[i] = 1
            if not visited[i]:
                if not bfs(graph, visited, color, i):
                    flag = False       
        print('YES') if flag else print('NO')
    
if __name__ == '__main__':
    main()