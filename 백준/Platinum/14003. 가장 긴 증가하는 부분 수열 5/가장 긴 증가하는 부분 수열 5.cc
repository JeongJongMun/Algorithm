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
    
    std::vector<int> arr(n);
    std::vector<int> dp;
    std::vector idx(n, 0);
    
    for (auto& elem : arr)
    {
        std::cin >> elem;
    }
    
    for (int i = 0; i < n; i++)
    {
        auto iter = std::lower_bound(dp.begin(), dp.end(), arr[i]);
        if (iter == dp.end())
        {
            idx[i] = dp.size();
            dp.push_back(arr[i]);
        }
        else
        {
            idx[i] = iter - dp.begin();
            *iter = arr[i];
        }
    }
    
    std::vector<int> ans;
    int target = dp.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (idx[i] == target - 1)
        {
            ans.push_back(arr[i]);
            target--;
        }
    }
    
    std::cout << dp.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        std::cout << ans[i] << " ";
    }
    
    return 0;
}