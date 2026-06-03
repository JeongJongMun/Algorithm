#include <iostream>
#include <string>
#include <vector>

int max(int a, int b)
{
    return a > b ? a : b;
}

int max_element(const std::vector<int>& container)
{
    if (container.size() <= 0) return 0;
    
    int result = container[0];
    for (const auto& elem : container)
    {
        result = max(result, elem);
    }
    
    return result;
}

int solution(std::vector<int> money) 
{
    /*
    dp[i] = max(money[i] + money[i - 2], money[i - 1])
    
    첫 집과 마지막 집이 동시에 포함될 수 있음.
    e.g. 100 1 10 5 100
    
    1. 첫 집을 털지 않는 경우 (마지막 집은 털거나 털지 않거나를 포함)
    2. 마지막 집을 털지 않는 경우 (첫 집은 털거나 털지 않거나를 포함)
    두 경우로 나눠서 계산
    */
    
    int n = money.size();
    
    // 마지막 집을 털지 않는 경우
    std::vector<int> dp1(n, 0);
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for (int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(money[i] + dp1[i - 2], dp1[i - 1]);
    }
    
    // 첫 집을 털지 않는 경우
    std::vector<int> dp2(n, 0);
    dp2[1] = money[1];
    for (int i = 2; i < n; i++)
    {
        dp2[i] = max(money[i] + dp2[i - 2], dp2[i - 1]);
    }
    
    return max(dp1[n - 2], dp2[n - 1]);
}