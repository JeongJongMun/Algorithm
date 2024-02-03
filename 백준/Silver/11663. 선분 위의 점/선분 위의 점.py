import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

def main():
    _, m = map(int, input().split())
    dot = sorted(list(map(int, input().split())))
    line = [list(map(int, input().split())) for _ in range(m)]
    for s, e in line:
        print(bisect_right(dot, e) - bisect_left(dot, s))
    
if __name__ == "__main__":
    main()