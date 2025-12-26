#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct node
{
    int end;
    int cost;
    
    node(const int inEnd, const int inCost) : end(inEnd), cost(inCost) {}
    
    bool operator<(const node& other) const
    {
        return cost > other.cost;
    }
};

int N, M;

void Dijkstra(std::vector<std::vector<node>>& graph, int start, int end)
{
    std::vector dist(N + 1, INT_MAX);
    dist[start] = 0;
    
    std::priority_queue<node> pq;
    pq.emplace(start, 0);
    
    std::vector backtracking(N + 1 , -1);
    
    while (!pq.empty())
    {
        auto [node, cost] = pq.top();
        pq.pop();
        
        if (dist[node] < cost) continue;
        
        for (auto& [adj_node, adj_cost] : graph[node])
        {
            if (dist[adj_node] > dist[node] + adj_cost)
            {
                dist[adj_node] = dist[node] + adj_cost;
                pq.emplace(adj_node, dist[adj_node]);
                
                backtracking[adj_node] = node;
            }
        }
    }
    
    std::vector<int> path;
    for (int i = end; i != -1; i = backtracking[i])
    {
        path.emplace_back(i);
    }
    std::reverse(path.begin(), path.end());
    
    std::cout << dist[end] << '\n' << path.size() << '\n';
    for (const auto& elem : path)
    {
        std::cout << elem << ' ';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> N >> M;
    
    std::vector graph(N + 1, std::vector<node>());
    
    int s, e, c;
    for (int i = 0; i < M; i++)
    {
        std::cin >> s >> e >> c;
        graph[s].emplace_back(e, c);
    }
    
    int start, end;
    std::cin >> start >> end;
    
    Dijkstra(graph, start, end);

    return 0;
}