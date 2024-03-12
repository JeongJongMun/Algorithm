import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    points.append(points[0])
    
    area = 0
    for i in range(n):
        area += points[i][0] * points[i + 1][1] - points[i + 1][0] * points[i][1]
    
    print(abs(area / 2))
if __name__ == "__main__":
    main()