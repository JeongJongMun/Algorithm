#include <vector>
#include <queue>
#include <iostream>

struct Edge
{
    int e;
    int c;
    
    Edge(int end, int cost) : e(end), c(cost) { }
    
    bool operator<(const Edge& other) const
    {
        return c > other.c;
    }
};

int solution(int n, std::vector<std::vector<int>> costs) 
{    
    std::priority_queue<Edge> pq;
    std::vector<std::vector<Edge>> graph(n, std::vector<Edge>());
    for (const auto& cost : costs)
    {
        graph[cost[0]].emplace_back(cost[1], cost[2]);
        graph[cost[1]].emplace_back(cost[0], cost[2]);
    }
    std::vector<bool> visited(n, false);
    visited[0] = true;
    int answer = 0;

    for (const auto& edge : graph[0])
    {
        pq.emplace(edge);
    }

    while (!pq.empty())
    {
        Edge edge = pq.top();
        pq.pop();
        
        if (visited[edge.e]) continue;

        answer += edge.c;
        visited[edge.e] = true;
        
        for (const auto& next : graph[edge.e])
        {
            if (!visited[next.e])
            {
                pq.emplace(next);
            }
        }
    }
    
    
    
    return answer;
}