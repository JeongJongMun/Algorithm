import sys
from heapq import heappush
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    ans = 1e9
    pack, each = [], []
    for _ in range(m):
        a, b = map(int, input().split())
        heappush(pack, a)
        heappush(each, b)
        ans = min(((n // 6) * pack[0]) + ((n % 6) * each[0]), ((n // 6) * pack[0]) + pack[0], (each[0] * n))
            
    print(ans)
     
if __name__ == "__main__":
    main()