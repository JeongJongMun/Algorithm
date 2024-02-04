import sys
input = sys.stdin.readline

def main():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        ps = [0] + list(map(int, input().split()))
        for i in range(1, n + 1):
            ps[i] += ps[i - 1]
        
        ans = -1e9
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                ans = max(ans, ps[j] - ps[i - 1])
        print(ans) if ans != -1e9 else print(ps[-1])
    
if __name__ == "__main__":
    main()
