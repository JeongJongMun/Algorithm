import sys, math
input = sys.stdin.readline

def walk(graph, inside, visited, start):
    stack = [start]
    visited[start] = 1
    cnt = 0
    while stack:
        node = stack.pop()
        for next_node in graph[node]:
            if inside[next_node]:
                cnt += 1
                visited[next_node] = 1
            if not visited[next_node]:
                stack.append(next_node)
                visited[next_node] = 1
    return math.factorial(cnt)/math.factorial(cnt-2) if cnt >= 2 else 0
                  
def main():
    v = int(input().strip())
    inside = list(map(int, input().strip()))
    inside = [0] + inside
    graph = [[] for _ in range(v + 1)]
    visited = [0 for _ in range(v + 1)]
    ans = 0

    for _ in range(v - 1):
        a, b = map(int, input().strip().split())
        graph[a].append(b)
        graph[b].append(a)
        ans += 2 if inside[a] and inside[b] else 0

    flag = True
    for i in range(2, len(graph) -1):
        if len(graph[i]) != 2:
            flag = False
            break
    if flag:
        print(max(0, (sum(inside) - 1) * 2))
        exit()
        
    for start in range(1, v + 1):
        if not inside[start] and not visited[start]:
            ans += walk(graph, inside, visited, start)
    
    print(int(ans))
    
if __name__ == '__main__':
    main()