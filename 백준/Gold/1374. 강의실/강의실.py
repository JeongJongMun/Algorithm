import sys
from heapq import heappush, heapreplace
input = sys.stdin.readline

def main():
    arr = []
    for _ in range(int(input().strip())):
        n, s, e = map(int, input().split())
        arr.append((s, e, n))
    arr.sort()

    s, e, n = arr[0]
    pq = [(e, s, n)]
    for s, e, n in arr[1:]:
        if pq[0][0] <= s:
            heapreplace(pq, (e, s, n))
        else:
            heappush(pq, (e, s, n))

    print(len(pq))

if __name__ == "__main__":
    main()