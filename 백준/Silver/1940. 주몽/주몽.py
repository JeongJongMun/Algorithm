import sys
input = sys.stdin.readline
    
def main():
    n = int(input())
    m = int(input())
    arr = sorted(list(map(int, input().split())))
    
    low = cnt = 0
    high = n - 1
    while low < high:
        if arr[low] + arr[high] == m:
            cnt += 1
            low += 1
            high -= 1
        elif arr[low] + arr[high] > m:
            high -= 1
        elif arr[low] + arr[high] < m:
            low += 1
    print(cnt)
if __name__ == "__main__":
    main()