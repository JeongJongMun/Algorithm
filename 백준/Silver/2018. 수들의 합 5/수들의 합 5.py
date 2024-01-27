import sys
input = sys.stdin.readline
    
def main():
    n = int(input())
    cnt = low = 0
    high = 1
    while high <= n:
        cal = (low + high) * (high - low + 1) / 2
        if cal == n:
            cnt += 1
            high += 1
            low += 1
        elif cal > n:
            low += 1
        elif cal < n:
            high += 1
    
    print(cnt)
if __name__ == "__main__":
    main()
