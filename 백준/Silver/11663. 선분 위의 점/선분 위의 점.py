import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    dot = sorted(list(map(int, input().split())))
    line = [list(map(int, input().split())) + [0] for _ in range(m)]
    for idx, (s, e, c) in enumerate(line):
        line[idx][2] = bisect_right(dot, e) - bisect_left(dot, s)
    for s, e, c in line:
        print(c)
    
if __name__ == "__main__":
    main()