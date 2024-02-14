import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    s = dict()
    for _ in range(n):
        site, pw = map(str, input().split())
        s[site] = pw
    
    for _ in range(m):
        print(s[input().strip()])
    
if __name__ == "__main__":
    main()