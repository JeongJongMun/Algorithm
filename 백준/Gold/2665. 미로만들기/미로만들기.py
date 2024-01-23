import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

def BFS(room):
    N = len(room)
    cnt = [[5000] * N for _ in range(N)]
    cnt[0][0] = 0
    que = deque([(0,0)])
    
    while que:
        x, y = que.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx >= 0 and nx < N and ny >= 0 and ny < N and cnt[nx][ny] >= cnt[x][y] + 1:
                que.append((nx, ny))
                cnt[nx][ny] = min(cnt[nx][ny], cnt[x][y] + 1) if room[nx][ny] == 0 else min(cnt[x][y], cnt[nx][ny])
    return cnt[N - 1][N - 1]

def main():
    room = [list(map(int, input().strip())) for _ in range(int(input().strip()))]
    print(BFS(room))
    
if __name__ == '__main__':
    main()