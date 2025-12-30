#include <iostream>
#define MAX 19
struct stone
{
    int color = 0;
    bool isChecked = false;
};

stone arr[MAX][MAX] = {};
int DIR_X[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int DIR_Y[] = {0, 0, -1 ,1, -1, 1, 1, -1};

bool Check(int y, int x)
{
    arr[y][x].isChecked = true;
    
    int color = arr[y][x].color;
    int cnt = 1;
    int ans_x = x;
    int ans_y = y;
    // 좌우 체크
    for (int j = x - 1; j >= 0 && arr[y][j].color == color; j--)
    {
        cnt++;
        ans_x = j;
    }
    for (int j = x + 1; j < MAX && arr[y][j].color == color; j++)
    {
        cnt++;
    }
    if (cnt == 5)
    {
        std::cout << color << '\n' << y + 1 << ' ' << ans_x + 1;
        return true;
    }
    
    cnt = 1;
    // 상하 체크
    for (int i = y - 1; i >= 0 && arr[i][x].color == color; i--)
    {
        cnt++;
    }
    for (int i = y + 1; i < MAX && arr[i][x].color == color; i++)
    {
        cnt++;
    }
    if (cnt == 5)
    {
        std::cout << color << '\n' << y + 1 << ' ' << x + 1;
        return true;
    }
    
    cnt = 1;
    ans_x = x;
    ans_y = y;
    // 왼쪽 아래 대각, 오른 위 대각 체크
    for (int i = y + 1, j = x - 1; i < MAX && j >= 0 && arr[i][j].color == color; i++, j--)
    {
        cnt++;
        ans_x = j;
        ans_y = i;
    }
    for (int i = y - 1, j = x + 1; i >= 0 && j < MAX && arr[i][j].color == color; i--, j++)
    {
        cnt++;
    }
    if (cnt == 5)
    {
        std::cout << color << '\n' << ans_y + 1 << ' ' << ans_x + 1;
        return true;
    }
    
    cnt = 1;
    ans_x = x;
    ans_y = y;
    // 왼쪽 위 대각, 오른 아래 대각 체크
    for (int i = y - 1, j = x - 1; i >= 0 && j >= 0 && arr[i][j].color == color; i--, j--)
    {
        cnt++;
        ans_x = j;
        ans_y = i;
    }
    for (int i = y + 1, j = x + 1; i < MAX && j < MAX && arr[i][j].color == color; i++, j++)
    {
        cnt++;
    }
    if (cnt == 5)
    {
        std::cout << color << '\n' << ans_y + 1 << ' ' << ans_x + 1;
        return true;
    }
    
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    
    for (auto& i : arr)
    {
        for (auto& j : i)
        {
            std::cin >> j.color;
        }
    }
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i][j].color != 0 && !arr[i][j].isChecked)
            {
                if (Check(i, j))
                {
                    return 0;
                }
            }
        }
    }
    
    std::cout << 0;
    
    return 0;
}