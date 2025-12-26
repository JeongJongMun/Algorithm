#include <iostream>
#include <vector>
#include <queue>

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int n, int m, int i, int j, std::vector<std::vector<int>>& adj, std::vector<std::vector<int>>& cnt) 
{
    std::queue<std::pair<int, int>> q;

    q.emplace(i, j);

    while (!q.empty()) 
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || adj[ny][nx] == 0 || cnt[ny][nx] != 0) continue;

            cnt[ny][nx] = cnt[y][x] + 1;
            q.emplace(ny, nx);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector graph(n, std::vector<int>(m));
    std::vector cnt(n, std::vector(m, 0));
    cnt[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j] - '0';
        }
    }

    bfs(n, m, 0, 0, graph, cnt);
    std::cout << cnt[n - 1][m - 1];
    
    return 0;
}