#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
    int y;
    int x;
    int dist;
    Node(int y, int x, int dist) : y(y), x(x), dist(dist) {}
    bool operator<(const Node& other) const
    {
        if (dist != other.dist)
            return dist > other.dist;
        if (y != other.y)
            return y > other.y;
        return x > other.x;
    }
};

int N;
int graph[20][20];
bool visit[20][20];
int bulk = 2;
int eatCnt = 0;
int ans;
const pair<int, int> DIR[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void Bfs(int i, int j)
{
    priority_queue<Node> pq;
    queue<Node> que;
    que.emplace(i, j, 0);
    visit[i][j] = true;

    while (!que.empty())
    {
        auto [y, x, dist] = que.front(); que.pop();
        
        for (auto [dy, dx] : DIR)
        {
            int ny = y + dy;
            int nx = x + dx;
            
            if (visit[ny][nx] or graph[ny][nx] > bulk) continue;
            if (ny > N - 1 or ny < 0 or nx > N - 1 or nx < 0) continue;

            if (graph[ny][nx] < bulk and graph[ny][nx] != 0 and !visit[ny][nx])
                pq.emplace(ny, nx, dist + 1);
            else
                que.emplace(ny, nx, dist + 1);
            visit[ny][nx] = true;
        }
    }

    if (!pq.empty())
    {
        auto [ny, nx, dist] = pq.top();
        memset(visit, false, sizeof(visit));
        graph[ny][nx] = 0;
        ans += dist;
        eatCnt++;
        if (eatCnt == bulk)
        {
            bulk++;
            eatCnt = 0;
        }
        
        Bfs(ny, nx);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    
    int startY = 0, startX = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                graph[i][j] = 0;
                startY = i;
                startX = j;
            }
        }
    }

    Bfs(startY, startX);

    cout << ans;
    
    return 0;
}