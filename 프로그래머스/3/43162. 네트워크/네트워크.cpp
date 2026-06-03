#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int start)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (start == i || graph[start][i] == 0 || visited[i])
        {
            continue;
        }
        visited[i] = true;
        dfs(graph, visited, i);
    }
}

int solution(int n, std::vector<std::vector<int>> graph) 
{
    std::vector<bool> visited(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        
        dfs(graph, visited, i);
        answer++;
    }
    
    return answer;
}