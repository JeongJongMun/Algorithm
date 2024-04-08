#include <iostream>
using namespace std;

char graph[100][100];
bool visit[100][100];
pair<int, int> DIR[4] = {
    {1, 0}, 
    {-1, 0}, 
    {0, -1}, 
    {0, 1}
};

int dfs(int n, int m, int i, int j, char c) {
    int cnt = 1;
    visit[i][j] = true;

    for (auto d : DIR) {
        int nx = j + d.first;
        int ny = i + d.second;
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !visit[ny][nx] && graph[ny][nx] == c) {
            cnt += dfs(n, m, ny, nx, c);
        }
    }
    return cnt;
}

int main()
{
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int w = 0, b = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                int cnt = dfs(n, m, i, j, graph[i][j]);
                if (graph[i][j] == 'W')
                    w += cnt * cnt;
                else
                    b += cnt * cnt;
            }
        }
    }
    cout << w << ' ' << b << '\n';

    return 0;
}
