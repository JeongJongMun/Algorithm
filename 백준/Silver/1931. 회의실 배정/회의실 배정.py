import sys
input = sys.stdin.readline
    
def main():
    n = int(input().strip())
    arr = []
    for _ in range(n):
        s, e = map(int, input().split())
        arr.append((e, s))
    arr.sort()
    
    end_time, _ = arr[0]
    cnt = 1
    for end, start in arr[1:]:
        if start >= end_time:
            end_time = end
            cnt += 1
    
    print(cnt)        
if __name__ == "__main__":
    main()