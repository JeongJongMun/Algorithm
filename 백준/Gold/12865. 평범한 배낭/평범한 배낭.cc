#include <iostream>
#include <vector>
#include <algorithm>

int DP[101][100001] = {};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> Weight(n + 1);
    std::vector<int> Value(n + 1);
    
    for (int i = 1; i <= n; i++)
    {
        std::cin >> Weight[i] >> Value[i];
    }
    
    for (int limit = 1; limit <= k; limit++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (Weight[i] > limit)
            {
                DP[i][limit] = DP[i - 1][limit];
            }
            else
            {
                DP[i][limit] = std::max(DP[i - 1][limit], DP[i - 1][limit - Weight[i]] + Value[i]);
            }
        }
    }
    
    std::cout << DP[n][k];
    
    return 0;
}

