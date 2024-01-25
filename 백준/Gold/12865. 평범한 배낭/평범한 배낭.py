import sys
input = sys.stdin.readline
    
def main():
    n, k = map(int, input().split())
    dp = [[0] * (n + 1) for _ in range(k + 1)]
    weight = [0] * (n + 1)
    value = [0] * (n + 1)
    
    for i in range(n):
        w, v = map(int, input().split())
        weight[i + 1], value[i + 1] = w, v
        
    for i in range(1, k + 1): # 무게
        for j in range(1, n + 1): # 물건
            if weight[j] > i:
                dp[i][j] = dp[i][j - 1]
            else:
                dp[i][j] = max(dp[i - weight[j]][j - 1] + value[j], dp[i][j - 1])
    
    print(dp[k][n])    
if __name__ == "__main__":
    main()