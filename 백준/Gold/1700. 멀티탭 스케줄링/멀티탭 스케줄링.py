import sys
from collections import deque
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    arr = deque(map(int, input().split()))
    multi = []
    cnt = 0
    while len(arr) > 0:
        if arr[0] in multi: 
            arr.popleft()
            continue
        
        if len(multi) < n: 
            multi.append(arr[0])
            arr.popleft()
            continue
        
        now = arr[0]
        idx = []
        for i in range(n):
            if multi[i] in arr:
                idx.append(arr.index(multi[i]))
            else:
                idx.append(101)
                break
        unplug_idx = idx.index(max(idx))
        multi[unplug_idx] = now
        cnt += 1
    print(cnt)
                
if __name__ == "__main__":
    main()