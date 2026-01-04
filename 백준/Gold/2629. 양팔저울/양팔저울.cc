#include <iostream>
#include <vector>

bool DP[31][40001] = {};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, k, sum = 0;
    
    std::cin >> n;
    std::vector<int> chu(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> chu[i];
        sum += chu[i];
    }
    
    std::cin >> k;
    std::vector<int> balls(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> balls[i];
    }

    for (int i = 0; i <= n; i++)
    {
        DP[i][0] = true;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - chu[i] >= 0 && DP[i - 1][j - chu[i]])
            {
                DP[i][j] = true;
            }
            if (DP[i - 1][j])
            {
                DP[i][std::abs(j - chu[i])] = true;
                DP[i][j] = true;
            }
        }
    }

    for (const auto& ball : balls)
    {
        if (DP[n][ball])
        {
            std::cout << "Y ";
        }
        else
        {
            std::cout << "N ";
        }
    }
    
    return 0;
}