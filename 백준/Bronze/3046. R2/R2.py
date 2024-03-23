import sys
input = sys.stdin.readline

def main():
    r1, s = map(int, input().split())
    for r2 in range(-1000, 1001):
        if (r1 + r2) / 2 == s:
            print(r2)
            break
if __name__ == "__main__":
    main()