from collections import deque

# 보드 크기, 사과 개수
N, K = int(input()), int(input())
board = [[0] * N for _ in range(N)]

# 사과 위치
for i in range(K):
    x, y = map(int, input().split())
    board[x-1][y-1] = 1

# 방향 변환
L = int(input())
change = []
for i in range(L):
    x, c = input().split()
    change.append((int(x), c))

# 0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
timer = dir = 0
# 뱀의 현재 위치
pos_queue = deque([(0, 0)])

while True:
    timer += 1
    x, y = pos_queue[-1]
    nx, ny = x + dx[dir], y + dy[dir]
    # 게임 끝
    if nx < 0 or nx >= N or ny < 0 or ny >= N or (nx, ny) in pos_queue:
        break
    if board[nx][ny] == 0:
        pos_queue.popleft()
    else:
        board[nx][ny] = 0
    pos_queue.append((nx, ny))
    
    if change and timer == change[0][0]:
        if change[0][1] == 'L':
            dir = (dir + 3) % 4
        else:
            dir = (dir + 1) % 4
        change.pop(0)
        
print(timer)