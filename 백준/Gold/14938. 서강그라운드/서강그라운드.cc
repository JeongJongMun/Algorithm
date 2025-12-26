#include <iostream>
#include <vector>
#define INT_MAX 1000000

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, r;
    std::cin >> n >> m >> r;

    std::vector graph(n, std::vector<int>(n));
    std::vector item_num(n, 0);

    for (int i = 0; i < n; i++)
    {
        std::fill(graph[i].begin(), graph[i].end(), INT_MAX);
        graph[i][i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> item_num[i];
    }

    for (int i = 0; i < r; i++)
    {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        start--;
        end--;
        graph[start][end] = cost;
        graph[end][start] = cost;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp_ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] <= m)
            {
                temp_ans += item_num[j];
            }
        }
        ans = std::max(ans, temp_ans);
    }
    
    std::cout << ans;
    
    return 0;
}