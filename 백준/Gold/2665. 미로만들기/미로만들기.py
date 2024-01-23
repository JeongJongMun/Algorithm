import sys
from collections import deque
input = sys.stdin.readline
dir = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def BFS(room):
    N = len(room)
    cnt = [[2500] * N for _ in range(N)]
    cnt[0][0] = 0
    que = deque([(0,0)])
    
    while que:
        x, y = que.popleft()
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            if nx >= 0 and nx < N and ny >= 0 and ny < N and cnt[nx][ny] >= cnt[x][y] + 1:
                que.append((nx, ny))
                cnt[nx][ny] = min(cnt[nx][ny], cnt[x][y] + 1) if room[nx][ny] == 0 else min(cnt[x][y], cnt[nx][ny])
    return cnt[N - 1][N - 1]

def main():
    room = [list(map(int, input().strip())) for _ in range(int(input().strip()))]
    print(BFS(room))
    
if __name__ == '__main__':
    main()