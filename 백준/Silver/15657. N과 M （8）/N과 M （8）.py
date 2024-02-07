import sys
from itertools import combinations_with_replacement
input = sys.stdin.readline

def main():
    _, m = map(int, input().split())
    arr = sorted(list(map(int, input().split())))
    for li in combinations_with_replacement(arr, m):
        print(*li)

if __name__ == "__main__":
    main()