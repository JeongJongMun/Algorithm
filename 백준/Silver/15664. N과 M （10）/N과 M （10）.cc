#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> arr(n);
    std::vector<bool> chosen(n, false);
    std::set<std::vector<int>> s; 
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        chosen[chosen.size() - i - 1] = true;
    }
    
    std::sort(arr.begin(), arr.end());
    
    do
    {
        std::vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (chosen[i])
            {
                temp.push_back(arr[i]);
            }
        }
        s.insert(temp);
    } while (std::next_permutation(chosen.begin(), chosen.end()));
    
    for (const auto& v : s)
    {
        for (const auto& elem : v)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}