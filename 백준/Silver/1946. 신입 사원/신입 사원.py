import sys
input = sys.stdin.readline
    
def main():
    for _ in range(int(input().strip())):
        arr = [tuple(map(int, input().split())) for _ in range(int(input().strip()))]
        arr.sort()
        cnt = 1
        m = arr[0][1]
        for i in range(1, len(arr)):
            if arr[i][1] < m:
                cnt += 1
                m = arr[i][1]
        print(cnt)

if __name__ == "__main__":
    main()