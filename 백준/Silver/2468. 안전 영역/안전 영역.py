x, y = [0, 0, -1, 1], [1, -1, 0, 0]
global cnt 
cnt = 0

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
max_h = max([max(i) for i in arr])

def bfs(si, sj, h):
    if visited[si][sj]:
        return
    if arr[si][sj] <= h:
        visited[si][sj] = True
        return
    
    queue = [(si, sj)]
    visited[si][sj] = True
    
    global cnt
    cnt += 1

    while queue:
        i, j = queue.pop(0)
        for k in range(len(x)):
            ni, nj = i + y[k], j + x[k]
            if ni < n and nj < n and ni >= 0 and nj >= 0 and arr[ni][nj] > h and visited[ni][nj] == False:
                queue.append((ni, nj))
                visited[ni][nj] = True
        
ans = 0
for h in range(max_h + 1):
    visited = [[False] * n for _ in range(n)]
    ans = max(ans, cnt)
    cnt = 0
    for i in range(n):
        for j in range(n):
            bfs(i, j, h)

print(ans)