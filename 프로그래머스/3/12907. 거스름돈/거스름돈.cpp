#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int solution(int n, std::vector<int> moneys)
{
    std::vector<unsigned long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for (const auto& money : moneys)
    {
        for (int i = money; i <= n; i++)
        {
            dp[i] += dp[i - money];
        }
    }
    return dp[n] % 1000000007;
}