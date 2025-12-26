#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector arr(n, 0);
    std::vector dp(n, 1);
    std::vector parent(n, -1);
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
                parent[i] = j;
            }
        }
    }
    
    auto iter = std::max_element(dp.begin(), dp.end());
    int last_idx = std::distance(dp.begin(), iter);
    
    std::vector<int> path;
    
    for (int i = last_idx; i != -1; i = parent[i])
    {
        path.push_back(arr[i]);
    }
    
    std::cout << *iter << "\n";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        std::cout << path[i] << " ";
    }

    return 0;
}