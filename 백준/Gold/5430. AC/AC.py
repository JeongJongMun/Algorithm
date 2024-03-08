import sys
from collections import deque
input = sys.stdin.readline

def main():
    for _ in range(int(input().strip())):
        functions = list(input().strip())
        input()
        str = input().strip().strip('[').strip(']')
        if str:
            arr = deque(str.split(','))
        else:
            arr = deque()
        status = True # if True -> popleft, if False -> pop
        is_done = True
        for command in functions:
            if command == 'R':
                status = False if status else True
            elif command == 'D':
                if len(arr) == 0:
                    print('error')
                    is_done = False
                    break
                elif status:
                    arr.popleft()
                elif not status: 
                    arr.pop()
        if is_done:
            print('[', end='')
            print(*arr if status else list(arr)[::-1] , sep=',', end='')
            print(']')
                
if __name__ == "__main__":
    main()