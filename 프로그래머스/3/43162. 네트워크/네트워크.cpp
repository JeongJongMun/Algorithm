#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int start)
{
    if (visited[start])
    {
        return false;
    }
    
    int n  = graph.size();

    std::stack<int> s;
    s.push(start);
    
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        
        for (int i = 0; i < n; i++)
        {
            if (node == i || !graph[node][i] || visited[i])
            {
                continue;
            }
            s.push(i);
            visited[i] = true;
        }
    }
    
    return true;
}

int solution(int n, std::vector<std::vector<int>> graph) 
{
    std::vector<bool> visited(n, false);
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (dfs(graph, visited, i))
        {
            answer++;
        }
    }
    
    return answer;
}