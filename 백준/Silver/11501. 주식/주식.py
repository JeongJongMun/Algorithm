import sys
input = sys.stdin.readline

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        stock = list(map(int, input().split()))

        ans = 0
        m = 0
        for i in range(n - 1, -1, -1):
            m = max(m, stock[i])
            ans += m - stock[i]
        print(ans)
if __name__ == "__main__":
    main()