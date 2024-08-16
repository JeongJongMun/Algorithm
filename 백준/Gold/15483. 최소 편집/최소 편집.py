def edit_distance(str1, str2):
    n = len(str1)
    m = len(str2)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        dp[i][0] = i
    for j in range(1, m + 1):
        dp[0][j] = j
        
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], # delete 
                               dp[i][j - 1],     # insert
                               dp[i - 1][j - 1]) # replace
    return dp[n][m]

ans = edit_distance(input(), input())
print(ans) # 3