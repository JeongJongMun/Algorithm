#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;
const pair<int, int> DIR[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M;
int graph[MAX][MAX];
bool visit[MAX][MAX];

int melted = 0;

void Bfs()
{
    int time = 0;
    int lastMelted = 0;
    while (true)
    {
        queue<pair<int, int>> que;
        que.emplace(0, 0);
        memset(visit, 0, sizeof(visit));
        
        visit[0][0] = true;
        melted = 0;
        
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
                    graph[dy][dx] = 0;
                    melted++;
                }
            }
        }

        if (melted == 0)
        {
            cout << time << '\n' << lastMelted << '\n';
            break;
        }
        lastMelted = melted;
        time++;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    Bfs();
    
    return 0;
}