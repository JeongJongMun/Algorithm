#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
    int y;
    int x;
    int dist;
    Node(int y, int x, int d) : y(y), x(x), dist(d) {}
};

int N, M;
char graph[50][50];
bool visit[50][50];
int ans;

queue<Node> que;

const pair<int, int> DIR[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int y, int x)
{
    if (graph[y][x] != 'L') return;
    que.emplace(y, x, 0);
    visit[y][x] = true;

    while (!que.empty())
    {
        auto [y, x, dist] = que.front(); que.pop();
        ans = max(ans, dist);

        for (auto [dy, dx] : DIR)
        {
            int ny = y + dy;
            int nx = x + dx;

            if (nx < 0 or nx >= M or ny < 0 or ny >= N or visit[ny][nx] or graph[ny][nx] == 'W') continue;

            que.emplace(ny, nx, dist + 1);
            visit[ny][nx] = true;
        }
    }
    
    memset(visit, false, sizeof(visit));
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
            graph[i][j] = s[j];
    }


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            bfs(i, j);

    cout << ans;
    
    return 0;
}