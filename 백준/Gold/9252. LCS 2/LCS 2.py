import sys
input = sys.stdin.readline

def main():
    a = input().strip()
    b = input().strip()
    dp = [[0] * (len(a) + 1) for _ in range(len(b) + 1)]
    for i in range(1, len(b) + 1):
        for j in range(1, len(a) + 1):
            if a[j - 1] == b[i - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])




    j, i = len(a), len(b)
    lcs = ''
    while i > 0 and j > 0:
        if dp[i][j] == dp[i - 1][j]:
            i -= 1
        elif dp[i][j] == dp[i][j - 1]:
            j -= 1
        else:    
            lcs = a[j - 1] + lcs
            i -= 1
            j -= 1
    
    print(dp[len(b)][len(a)])
    if lcs: print(lcs)

if __name__ == "__main__":
    main()