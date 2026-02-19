#include <iostream>
#include <vector>
#define MAX 1e9

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector graph(n, std::vector(n, MAX));
    for (int i = 0; i < m; i++)
    {
        int prev, next;
        std::cin >> prev >> next;
        prev--;
        next--;
        graph[prev][next] = 1;
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int s;
    std::cin >> s;
    
    for (int i = 0; i < s; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        
        if (graph[a][b] == MAX && graph[b][a] == MAX)
        {
            std::cout << '0' << '\n';
        }
        else if (graph[a][b] > graph[b][a])
        {
            std::cout << "1" << '\n';
        }
        else
        {
            std::cout << "-1" << '\n';
        }
    }
    
    return 0;
}
