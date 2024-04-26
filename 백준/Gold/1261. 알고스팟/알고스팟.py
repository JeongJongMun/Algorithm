import sys
from heapq import heappush, heappop
input = sys.stdin.readline
DIR = [(1, 0), (-1, 0), (0, 1), (0, -1)]
INT = int(1e9)

def main():
    m, n = map(int, input().split())
    maze = [list(map(int, input().strip())) for _ in range(n)]

    hq = [(0, 0, 0)]
    dist = [[INT] * m for _ in range(n)]
    dist[0][0] = 0
    
    while hq:
        cnt, x, y = heappop(hq)
        for dx, dy, in DIR:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n:
                
                next_dist = cnt + maze[ny][nx]
                if next_dist < dist[ny][nx]:
                    heappush(hq, (next_dist, nx, ny))
                    dist[ny][nx] = next_dist

    print(dist[n - 1][m -  1])

if __name__ == "__main__":
    main()