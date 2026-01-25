#include <iostream>
#include <vector>
#define MIN -1e9

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::vector dp(1002, std::vector<int>(1002, MIN));
    std::vector prefix_sum(1002, std::vector(1002, 0));
    
    int n, m;
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> dp[i][j];
            prefix_sum[i][j] = dp[i][j] + prefix_sum[i][j - 1];
        }
    }
    
    for (int j = 2; j <= m; j++)
    {
        dp[1][j] += dp[1][j - 1];
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += std::max(dp[i - 1][j], dp[i][j - 1]);
            
            for (int k = j - 1; k >= 1; k--)
            {
                dp[i][k] = std::max(dp[i][k], prefix_sum[i][j] - prefix_sum[i][k - 1] + dp[i - 1][j]);
            }
        }
    }
    
    std::cout << dp[n][m];
    
    return 0;
}