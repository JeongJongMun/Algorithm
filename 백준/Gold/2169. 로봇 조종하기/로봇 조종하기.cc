#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#define MIN -1e9

std::vector dp(1002, std::vector<int>(1002, MIN));
std::vector arr(1002, std::vector<int>(1002, MIN));
std::vector prefix_sum(1002, std::vector<int>(1002, 0));

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> arr[i][j];
            prefix_sum[i][j] = arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix_sum[i][j] += prefix_sum[i][j - 1];
        }
    }
    
    dp[1][1] = arr[1][1];
    for (int j = 2; j <= m; j++)
    {
        dp[1][j] = dp[1][j - 1] + arr[1][j];
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a = dp[i - 1][j] + arr[i][j];
            int b = dp[i][j - 1] + arr[i][j];
            dp[i][j] = std::max(a, b);
            
            for (int k = j - 1; k >= 1; k--)
            {
                int a = dp[i][k];
                int b = prefix_sum[i][j] - prefix_sum[i][k - 1] + dp[i - 1][j];
                dp[i][k] = std::max(a, b);
            }
        }
    }
    
    std::cout << dp[n][m];
    
    return 0;
}