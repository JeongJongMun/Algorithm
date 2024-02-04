import sys
input = sys.stdin.readline

def main():
    n = int(input().strip())
    prefix_sum = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        prefix_sum[i] += prefix_sum[i - 1]
            
    for _ in range(int(input().strip())):
        a, b = map(int, input().split())
        print(prefix_sum[b] - prefix_sum[a - 1])
    
if __name__ == "__main__":
    main()