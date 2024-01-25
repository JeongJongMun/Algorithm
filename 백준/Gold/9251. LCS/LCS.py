    
def main():
    s1 = input()
    s2 = input()
    
    width, height = len(s1) + 1, len(s2) + 1
    
    dp = [[0] * (width) for _ in range(height)]
    
    for i in range(1, height):
        for j in range(1, width):
            if s1[j - 1] == s2[i - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                
    print(dp[height - 1][width - 1])    
if __name__ == "__main__":
    main()