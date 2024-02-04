import sys
input = sys.stdin.readline

def main():
    n, x = map(int, input().split())
    ps = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        ps[i] += ps[i - 1]
    
    ans = cnt = 0
    for i in range(1, n - x + 2):
        temp = ps[i + x - 1] - ps[i - 1]
        if temp > ans:
            ans = temp
            cnt = 1
        elif temp == ans:
            cnt += 1
        
    print('SAD') if ans == 0 else print(ans, cnt, sep='\n')
    
if __name__ == "__main__":
    main()