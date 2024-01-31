import sys
input = sys.stdin.readline
INF = int(1e10)

def main():
    n = int(input().strip())
    arr = [tuple(map(int, input().split())) for _ in range(n)]
    dp = [[0] * n for _ in range(n)]
    
    for term in range(1, n):
        for i in range(n):
            if i + term == n: break

            dp[i][i+term] = INF
            
            for t in range(i, i+term):
                dp[i][i+term] = min(dp[i][i+term],
                                    dp[i][t] + dp[t+1][i+term] + arr[i][0] * arr[t][1] * arr[i+term][1])

    print(dp[0][n-1])
    
if __name__ == "__main__":
    main()