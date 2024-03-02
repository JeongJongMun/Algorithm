import sys
input = sys.stdin.readline
INF = int(1e9)

def main():
    n, s = map(int, input().split())
    arr = list(map(int, input().split()))
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]
    
    shortest_len = INF
    low, high = 0, 1
    while low < high and high < n + 1:
        cur = prefix_sum[high] - prefix_sum[low]
        if cur >= s:
            shortest_len = min(shortest_len, high - low)

        if cur > s:
            low += 1
        else:
            high += 1
    
    print(shortest_len if shortest_len < INF else 0)

if __name__ == "__main__":
    main()