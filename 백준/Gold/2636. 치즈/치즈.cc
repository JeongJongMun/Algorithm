#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int graph[100][100];
bool visit[100][100];
int cheeseCount = 0;
int bfsCount = 0;
const pair<int, int> DIR[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Node
{
    int y;
    int x;
    Node(int y, int x) : y(y), x(x) {}
};

int GraphSum()
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            sum += graph[i][j];
    
    return sum;
}

void Bfs(int y, int x)
{
    queue<Node> que;
    que.emplace(y, x);
    visit[y][x] = true;
    int temp[100][100];
    memcpy(temp, graph, sizeof(graph));

    cheeseCount = 0;
    bfsCount++;
    while (!que.empty())
    {
        auto [i, j] = que.front(); que.pop();
        
        for (auto [ny, nx] : DIR)
        {
            int dy = ny + i;
            int dx = nx + j;

            if (visit[dy][dx]) continue;
            if (dy > N - 1 or dy < 0 or dx > M - 1 or dx < 0) continue;
            
            visit[dy][dx] = true;
            
            if (graph[dy][dx] == 0)
                que.emplace(dy, dx);
            else
            {
                temp[dy][dx] = 0;
                cheeseCount++;
            }
        }
    }
    memcpy(graph, temp, sizeof(temp));
    memset(visit, 0, sizeof(visit));

    if (GraphSum() == 0)
        cout << bfsCount << '\n' << cheeseCount << '\n';
    else
        Bfs(0, 0);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    Bfs(0, 0);
    
    return 0;
}