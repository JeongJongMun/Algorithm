import sys
from collections import deque
input = sys.stdin.readline
JUMP = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
MOVE = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def bfs(graph, visited, k, w, h):
    que = deque([(0, 0, 0, 0)]) # x, y, 동작횟수, 점프횟수
    
    while que:
        x, y, cnt, jump_cnt = que.popleft()
        
        if x == w - 1 and y == h - 1:
            return cnt
        
        for dx, dy in MOVE:
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h and graph[ny][nx] == 0 and not visited[jump_cnt][ny][nx]:
                visited[jump_cnt][ny][nx] = True
                que.append((nx, ny, cnt + 1, jump_cnt)) 
                
        for dx, dy in JUMP:
            nx, ny = x + dx, y + dy
            if 0 <= nx < w and 0 <= ny < h and graph[ny][nx] == 0 and jump_cnt + 1 <= k and not visited[jump_cnt + 1][ny][nx]:
                visited[jump_cnt + 1][ny][nx] = True
                que.append((nx, ny, cnt + 1, jump_cnt + 1))
    return -1;        
def main():
    k = int(input().strip())
    w, h = map(int, input().split())
    graph = [list(map(int, input().split())) for _ in range(h)]
    visited = [[[False] * w for _ in range(h)] for _ in range(k + 1)]
    print(bfs(graph, visited, k, w, h))
    
if __name__ == "__main__":
    main()