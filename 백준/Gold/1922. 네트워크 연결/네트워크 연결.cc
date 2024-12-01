#include <iostream>
#include <queue>
using namespace std;

struct Edge
{
    int end = 0;
    int cost = 0;
    Edge(int e, int c) : end(e), cost(c) { }

    bool operator<(const Edge& other) const
    {
        return cost > other.cost;
    }
};

int N, M;

int main()
{
    priority_queue<Edge> pq;
    cin >> N >> M;
    int a, b, c;
    vector<bool> visit(N + 1);
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    pq.emplace(1, 0);
    int ans = 0;
    while (!pq.empty())
    {
        auto [end, cost] = pq.top(); pq.pop();
        if (visit[end]) continue;

        visit[end] = true;
        ans += cost;
        for (auto [e, c] : graph[end])
        {
            if (visit[e]) continue;
            pq.emplace(e, c);
        }
    }

    cout << ans;
    
    return 0;
}