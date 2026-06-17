#include <vector>

using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}

void floyd(vector<vector<int>>& graph)
{
    int n = graph.size();
    for (int k = 1; k < n; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 100000000));
    
    for (int i = 0; i <= n; i++) 
    {
        graph[i][i] = 0;
    }
    
    for (const auto& fare : fares)
    {
        graph[fare[0]][fare[1]] = fare[2];
        graph[fare[1]][fare[0]] = fare[2];
    }
    
    floyd(graph);
    
    int answer = 100000000;
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                answer = min(answer, graph[s][k] + graph[k][a] + graph[k][b]);
            }
        }
    }
    
    return answer;
}