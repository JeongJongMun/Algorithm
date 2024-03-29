import sys
input = sys.stdin.readline
    
def main():
    n = int(input())
    dp = [0] * (n + 1)
    dp[0] = dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746
        
    print(dp[n])
if __name__ == "__main__":
    main()