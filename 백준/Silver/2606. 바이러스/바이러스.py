import sys
input = sys.stdin.readline
cnt = 0
            
def dfs(graph, visited, start):
    visited[start] = 1
    global cnt
    cnt += 1 if start != 1 else 0
    for node in graph[start]:
        if not visited[node]:
            dfs(graph, visited, node)
                

def main():
    v = int(input().strip())
    e = int(input().strip())
    graph = [[] for _ in range(v + 1)]
    visited = [0] * (v + 1)
    
    for _ in range(e):
        a, b = map(int, input().split())
        graph[a] += [b]
        graph[b] += [a]
        
    dfs(graph, visited, 1)
    print(cnt)
if __name__ == '__main__':
    main()