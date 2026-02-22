#include <iostream>
#include <string>
#include <vector>
#define MAX 1e9

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    

    int n, m;
    std::cin >> n >> m;

    std::vector dist(n, std::vector<int>(n, MAX));
    std::vector ans(n, std::vector(n, std::vector<int>()));
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        
        dist[a][b] = std::min(dist[a][b], c);
    }
    
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ans[i][j].clear();
                    for (const auto elem : ans[i][k])
                    {
                        ans[i][j].push_back(elem);
                    }
                    ans[i][j].push_back(k);
                    for (const auto elem : ans[k][j])
                    {
                        ans[i][j].push_back(elem);
                    }
                }
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || dist[i][j] == MAX)
            {
                std::cout << 0 << ' ';
            }
            else
            {
                std::cout << dist[i][j] << ' ';
            }
        }
        std::cout << '\n';
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || dist[i][j] == MAX)
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::cout << ans[i][j].size() + 2 << ' ' << i + 1 << ' ';
                
                for (const auto elem : ans[i][j])
                {
                    std::cout << elem + 1 << ' ';
                }
                std::cout << j + 1 << '\n';
            }
        }
    }
    
    return 0;
}
