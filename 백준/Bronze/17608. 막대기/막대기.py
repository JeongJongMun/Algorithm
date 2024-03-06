import sys
input = sys.stdin.readline

def main():
    bar = []
    for _ in range(int(input().strip())):
        x = int(input().strip())
        bar.append(x)
    
    m = bar[-1] 
    ans = 1
    for i in range(len(bar) - 2, -1, -1):
        if bar[i] > m:
            ans += 1
            m = bar[i]
    
    print(ans)
    
if __name__ == "__main__":
    main()