import sys
input = sys.stdin.readline
    
def main():
    n, k = map(int, input().split())
    coin = [int(input()) for _ in range(n)]
    
    cnt = 0
    for i in range(n - 1, -1, -1):
        cnt += k // coin[i]
        k %= coin[i]
    print(cnt)

if __name__ == "__main__":
    main()