#include <iostream>
#include <vector>
#define MAX 1e9

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector dist(n, std::vector(n, MAX));
    
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < n; ++i)
    {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < n; ++j)
        {
            if (line[j] == 'Y')
            {
                dist[i][j] = 1;
            }
        }
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (const auto& row : dist)
    {
        int cnt = 0;
        for (const auto& cell : row)
        {
            if (cell < 3)
            {
                cnt++;
            }
        }
        ans = std::max(ans, cnt - 1);
    }
    
    std::cout << ans;
    
    return 0;
}
