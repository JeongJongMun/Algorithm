import sys
input = sys.stdin.readline

def main():
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(int(input()))
    
    arr.sort()
    ans = 0
    for i in range(n - 1, -1, -1):
        ans = max(ans, arr[i]*(n-i))
    print(ans)
                
if __name__ == "__main__":
    main()