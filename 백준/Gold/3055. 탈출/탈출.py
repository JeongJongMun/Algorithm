import sys
from collections import deque
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def bfs(arr, r, c):
    que = deque((i, j) for j in range(c) for i in range(r) if arr[i][j] == 1)
    que.extend([(i, j) for i in range(r) for j in range(c) if arr[i][j] == -1])

    # for i in range(r):
    #     for j in range(c):
    #         if arr[i][j] == -1:
    #             que.append((i,j))
    while que:
        y, x = que.popleft()
        for dy, dx in DIR:
            ny, nx = y + dy, x + dx
            if 0 <= ny < r and 0 <= nx < c and arr[ny][nx] != 'X':
                if arr[y][x] >= 1:
                    if arr[ny][nx] == 'D': return arr[y][x]
                    if arr[ny][nx] == 0:
                        que.append((ny, nx))
                        arr[ny][nx] = arr[y][x] + 1

                elif arr[y][x] == -1:
                    if arr[ny][nx] != 'D' and arr[ny][nx] != -1:
                        que.append((ny, nx))
                        arr[ny][nx] = -1
        # print()
        # print(*arr, sep='\n')
  
    return 'KAKTUS'
                
                
def main():
    r, c = map(int, input().split())
    arr = [[0] * c for _ in range(r)]
    for row in range(r):
        string = input().strip()
        for col, elem in enumerate(string):
            match elem:
                case 'D':
                    arr[row][col] = 'D'
                case '*':
                    arr[row][col] = -1
                case 'X':
                    arr[row][col] = 'X'
                case 'S':
                    arr[row][col] = 1
                case default:
                    arr[row][col] = 0
    
    # print(*arr, sep='\n')
    print(bfs(arr, r, c))
   
if __name__ == "__main__":
    main()
    
'''
고슴도치 S = 1
물 * = -1
돌 X = X
비버 굴 D = D
그냥 땅 = 0

2 2
**
DS

1
'''