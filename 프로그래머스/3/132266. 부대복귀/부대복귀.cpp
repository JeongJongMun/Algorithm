#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(int n, vector<vector<int>> edges, 
                     vector<int> starts, int dest) 
{

    vector<vector<int>> graph(n + 1);
    
    for (const auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<int> dist(n + 1, 1e9);
    dist[dest] = 0;
    vector<bool> visited(n + 1, false);
    visited[dest] = true;
    
    queue<int> q;
    q.push(dest);
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (const auto& next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                dist[next] = dist[node] + 1;
            }
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < starts.size(); i++)
    {
        int cost = dist[starts[i]];
        answer.push_back(cost != 1e9 ? cost : -1);
    }
    
    return answer;
}