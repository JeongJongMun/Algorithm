#include <iostream>
#include <queue>
#include <vector>

const long long INF = 1e18;

struct edge
{
    int to;
    int weight;
};

bool spfa(int n, int m, std::vector<std::vector<edge>>& graph, std::vector<long long>& dist)
{
    std::vector count(n + 1, 0);
    std::vector inQue(n + 1, false);
    std::queue<int> que;
    
    int start = 1;
    dist[start] = 0;
    que.push(start);
    inQue[start] = true;
    count[start]++;
    
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        inQue[cur] = false;
        
        for (const auto& edge : graph[cur])
        {
            int to = edge.to;
            int weight = edge.weight;
            
            if (dist[to] > dist[cur] + weight)
            {
                dist[to] = dist[cur] + weight;
                
                if (!inQue[to]) 
                {
                    que.push(to);
                    inQue[to] = true;
                    count[to]++;
                
                    if (count[to] >= n)
                    {
                        return true;
                    }
                }
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
    
    std::vector graph(n + 1, std::vector<edge>());
    std::vector dist(n + 1, INF);
    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    if (spfa(n, m, graph, dist))
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