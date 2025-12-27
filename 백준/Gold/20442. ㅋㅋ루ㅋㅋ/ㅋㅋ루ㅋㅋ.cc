#include <iostream>
#include <queue>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int num_k = 0, num_r = 0;
    
    for (const auto& elem : s)
    {
        if (elem == 'K')
        {
            num_k++;
        }
        if (elem == 'R')
        {
            num_r++;
        }
    }
    
    int left = -1;
    int right = s.length();
    int answer = 0;
    int target_idx = num_k / 2 + 1;
    
    for (int i = 0; i < target_idx ; i++)
    {
        if (num_r == 0) break;
        
        answer = std::max(answer, 2 * i + num_r);
        
        left += 1;
        right -= 1;
        
        while (left < right && s[left] != 'K')
        {
            left += 1;
            num_r -= 1;
        }
        while (left < right && s[right] != 'K')
        {
            right -= 1;
            num_r -= 1;
        }
    }
    
    std::cout << answer;
    
    return 0;
}