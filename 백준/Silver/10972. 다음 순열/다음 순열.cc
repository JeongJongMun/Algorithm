#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    std::vector<int> temp = arr;
    std::sort(temp.begin(), temp.end());
    
    std::next_permutation(arr.begin(), arr.end());
    
    if (arr == temp)
    {
        std::cout << -1;
        return 0;
    }

    for (const auto& elem : arr)
    {
        std::cout << elem << " ";
    }
    
    return 0;
}
 