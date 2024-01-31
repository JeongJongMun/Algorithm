import sys
from collections import deque
input = sys.stdin.readline

def main():
    n = int(input().strip())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    a.sort()
    b.sort()
    
    cnt = 0
    for i in range(n):
        cnt += a[i] * b[n - i - 1]
    
    print(cnt)
                
if __name__ == "__main__":
    main()