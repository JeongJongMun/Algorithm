#include <iostream>
#include <vector>

const long long INF = 1e18;

struct edge
{
    int from;
    int to;
    int weight;
};

bool bellman_ford(int n, int m, std::vector<edge>& edges, std::vector<long long>& dist)
{
    dist[1] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;
            
            if (dist[from] != INF && dist[to] > dist[from] + weight)
            {
                dist[to] = dist[from] + weight;
                
                if (i == n) return true;
            }
        }
    }
    
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<edge> edges(m);
    std::vector dist(n + 1, INF);
    
    for (int i = 0; i < m; i++)
    {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    if (bellman_ford(n, m, edges, dist))
    {
        std::cout << -1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
            {
                std::cout << -1 << '\n';
            }
            else
            {
                std::cout << dist[i] << '\n';
            }
        }
    }
    
    return 0;
}