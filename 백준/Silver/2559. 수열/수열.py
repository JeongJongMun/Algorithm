import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    temper = list(map(int, input().split()))
    low, high = 0, k - 1
    s = sum(temper[:k])
    ans = s
    while high < n - 1:
        s -= temper[low]
        low += 1
        high += 1
        s += temper[high]
        ans = max(ans, s)
    print(ans)
if __name__ == "__main__":
    main()