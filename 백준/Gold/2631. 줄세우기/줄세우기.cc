#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; 
    std::cin >> N;
    
    std::vector<int> arr(N);
    std::vector<int> dp(N, 1);
    
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << N - *std::max_element(dp.begin(), dp.end());

    return 0;
}