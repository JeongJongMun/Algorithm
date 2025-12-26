#include <iostream>
#include <vector>
#include <queue>

// 비용, 정점 번호
using edge = std::pair<int, int>;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector visited(n + 1, false);
    std::vector graph(n + 1, std::vector<edge>());
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }

    pq.emplace(0, 1);

    int ans = 0;
    int max_edge_weight = 0;
    
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        
        visited[node] = true;
        ans += weight;
        max_edge_weight = std::max(weight, max_edge_weight);

        for (const auto& next_edge : graph[node])
        {
            int next_weight = next_edge.first;
            int next_node = next_edge.second;

            if (!visited[next_node])
            {
                pq.emplace(next_weight, next_node);
            }
        }
    }

    std::cout << ans - max_edge_weight;
    
    return 0;
}