import sys
from heapq import heappop, heappush
input = sys.stdin.readline
INF = int(1e9)


def main():
    n, m = map(int, input().split())

    stu = [list(map(int, input().split())) for _ in range(n)]
    idx = [1] * 1001
    
    for i in range(n):
        stu[i].sort()
    
    hq = []
    max_value = 0
    for i in range(n):
        heappush(hq, (stu[i][0], i))
        max_value = max(max_value, stu[i][0])

    ans = INF
    while hq:
        min_value, index = heappop(hq)
        ans = min(ans, max_value - min_value)
        
        if idx[index] == m:
            break

        next = stu[index][idx[index]]
        heappush(hq, (next, index))
        max_value = max(max_value, next)
        idx[index] += 1
        

    
    print(ans)

if __name__ == "__main__":
    main()
