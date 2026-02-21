#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Edge
{
    int end;
    int cost;

    Edge(int e, int c) : end(e), cost(c) {}

    bool operator<(const Edge& e) const
    {
        return this->cost > e.cost;
    }
};

int N, M;
vector<vector<Edge>> adj(1001);
vector<int> distances(1001, 1e9);
vector visit(1001, false);

int dijkstra(int start, int end)
{
    priority_queue<Edge> pq;

    distances[start] = 0;
    pq.emplace(start, 0);

    while (!pq.empty())
    {
        auto [cur, cost] = pq.top(); pq.pop();
        if (visit[cur]) continue;
        
        for (auto [next, dist] : adj[cur])
        {
            if (distances[next] > distances[cur] + dist)
            {
                visit[cur] = true;
                distances[next] = distances[cur] + dist;
                pq.emplace(next, distances[next]);
            }
        }
        
    }
    
    return distances[end];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e, c; cin >> s >> e >> c;
        adj[s].emplace_back(e, c);
    }
    int start, end; cin >> start >> end;

    cout << dijkstra(start, end) << '\n';
    
    return 0;
}