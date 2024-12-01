#include <iostream>
#include <cstring>
using namespace std;

int room[50][50];
int R, C, T, Air;
const pair<int, int> DIR[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void Spread()
{
    int temp[50][50] = {0, };
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] == -1)
            {
                temp[i][j] = -1;
                continue;
            }
            if (room[i][j] == 0) continue;
            
            int spreadNum = room[i][j] / 5;
            for (auto [first, second] : DIR)
            {
                int next_i = i + first;
                int next_j = j + second;
                if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C || room[next_i][next_j] == -1) continue;
                room[i][j] -= spreadNum;
                temp[next_i][next_j] += spreadNum;
            }
            temp[i][j] += room[i][j];
        }
    }
    memcpy(room, temp, sizeof(room));
}

void Clean()
{
    int up = Air - 1;
    int down = Air;
    for (int i = up - 1; i > 0; i--)
    {
        room[i][0] = room[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++)
    {
        room[0][i] = room[0][i + 1];
    }
    for (int i = 0; i < up; i++)
    {
        room[i][C - 1] = room[i + 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--)
    {
        room[up][i] = room[up][i - 1];
    }
    room[up][1] = 0;

    for (int i = down + 1; i < R - 1; i++)
    {
        room[i][0] = room[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++)
    {
        room[R - 1][i] = room[R - 1][i + 1];
    }
    for (int i = R - 1; i > down; i--)
    {
        room[i][C - 1] = room[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--)
    {
        room[down][i] = room[down][i - 1];
    }
    room[down][1] = 0;
}

int main()
{
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
                Air = i;
        }
    }
    for (int i = 0; i < T; i++)
    {
        Spread();
        Clean();
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] == -1) continue;
            ans += room[i][j];
        }
    }
    cout << ans;
    
    return 0;
}