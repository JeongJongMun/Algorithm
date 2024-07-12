import sys
sys.setrecursionlimit(10**6)

def dfs(graph, visit, node, depth = 1):
    visit[node] = True
    
    for next in graph[node]:
        if not visit[next]:
            dfs(graph, visit, next, depth + 1)
            
    visit[node] = False
    if depth >= 5:
        print(1)
        quit()

def main():
    v, e = map(int, input().split())
    graph = [[] for _ in range(v)]
    
    for _ in range(e):
        start, end = map(int, input().split())
        graph[start].append(end)
        graph[end].append(start)
    
    for i in range(v):
        visit = [False] * v
        dfs(graph, visit, i)

    print(0)
if __name__ == "__main__":
    main()