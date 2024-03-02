import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    n, s = map(int, input().split())
    arr = list(map(int, input().split()))
    ans = INF
    low, high = 0, 0
    cur = arr[0]
    while low <= high:
        if cur >= s:
            ans = min(ans, high - low + 1)

        if cur <= s and high != n - 1:
            high += 1
            cur += arr[high]
        else:
            cur -= arr[low]
            low += 1
    
    print(ans if ans < INF else 0)

if __name__ == "__main__":
    main()