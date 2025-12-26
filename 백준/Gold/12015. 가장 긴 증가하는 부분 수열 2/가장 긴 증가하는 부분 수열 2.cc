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
    
    for (auto& elem : arr)
    {
        std::cin >> elem;
    }
    
    for (int i = 0; i < n; i++)
    {
        auto iter = std::lower_bound(dp.begin(), dp.end(), arr[i]);
        if (iter == dp.end())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            *iter = arr[i];
        }
    }
    
    std::cout << dp.size() << "\n";
    
    return 0;
}