import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        arr = list(map(str, input().split()))
        ans = INF
        if n > 32:
            print(0)
        else:
            for i in range(0, n - 2):
                for j in range(i + 1, n - 1):
                    for k in range(j + 1, n):
                        cnt = 0
                        for idx in range(4):
                            if arr[i][idx] != arr[j][idx]: cnt += 1
                            if arr[i][idx] != arr[k][idx]: cnt += 1
                            if arr[j][idx] != arr[k][idx]: cnt += 1
                        ans = min(ans, cnt)
            print(ans)
if __name__ == "__main__":
    main()