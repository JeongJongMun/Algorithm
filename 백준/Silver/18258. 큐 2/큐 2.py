from collections import deque
import sys
input = sys.stdin.readline

N = int(input().strip())
que = deque()

for _ in range(N):
    command = input().strip().split()
    if command[0] == 'push':
        que.append(command[1])
    elif command[0] == 'pop':
        print(que.popleft() if len(que) else -1)
    elif command[0] == 'size':
        print(len(que))
    elif command[0] == 'empty':
        print(0 if len(que) else 1)
    elif command[0] == 'front':
        print(que[0] if len(que) else -1)
    elif command[0] == 'back':
        print(que[-1] if len(que) else -1)