import sys
sys.setrecursionlimit(10**6)

def dfs(graph, visit, node, cnt = -1):
    visit[node] = True
    
    for next in graph[node]:
        if not visit[next]:
            cnt = dfs(graph, visit, next, cnt)
    
    return cnt + 1
def main():
    v, e = int(input()), int(input())
    graph = [[] for _ in range(v + 1)]
    visit = [False] * (v + 1)
    
    for _ in range(e):
        start, end = map(int, input().split())
        graph[start].append(end)
        graph[end].append(start)
    
    answer = dfs(graph, visit, 1)
    print(answer)
if __name__ == "__main__":
    main()