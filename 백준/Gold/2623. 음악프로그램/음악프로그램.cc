#include <iostream>
#include <queue>
#include <vector>

int N, M;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> N >> M;
    
    std::vector graph(N + 1, std::vector<int>());
    std::vector indegree(N + 1, 0);
    
    for (int i = 0; i < M; i++)
    {
        int input_cnt;
        std::cin >> input_cnt;
        
        std::vector<int> temp(input_cnt);
        for (int j = 0; j < input_cnt; j++)
        {
            std::cin >> temp[j];
        }
        
        for (int j = 0; j < input_cnt - 1; j++)
        {
            int start = temp[j];
            int end = temp[j + 1];
            graph[start].emplace_back(end);
            indegree[end]++;
        }
    }
    
    
    std::queue<int> que;
    std::vector<int> answer;
    for (int i = 1; i < N + 1; i++)
    {
        if (indegree[i] == 0)
        {
            que.emplace(i);
        }
    }
    
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        answer.emplace_back(node);
        
        for (const auto& adj_node : graph[node])
        {
            if (--indegree[adj_node] == 0)
            {
                que.emplace(adj_node);
            }
        }
    }
    
    if (answer.size() == N)
    {
        for (const auto& elem : answer)
        {
            std::cout << elem << '\n';
        }
    }
    else
    {
        std::cout << 0;
    }

    return 0;
}