#include <iostream>

int ans = 987654321;
int ladder[31][11];
int n,m,h;

bool isManipulated()
{
    for (int j = 1; j <= n; ++j)
    {
        int col = j;
        for (int i = 1; i <= h; ++i)
        {
            if (ladder[i][col])
                col++;
            else if (ladder[i][col - 1])
                col--;
        }

        if (col != j)
        {
            return false;
        }
    }

    return true;
}

void dfs(int maxDepth,int cnt)
{
    if (maxDepth == cnt)
    {
        if (isManipulated())
        {
            std::cout << maxDepth;
            exit(0);
        }

        return;
    }

    for (int j = 1; j < n; ++j) 
    {
        for (int i = 1; i <= h; ++i)
        {
            if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
            ladder[i][j] = 1;
            dfs(maxDepth, cnt + 1);
            ladder[i][j] = 0;

            while (!ladder[i][j-1] && !ladder[i][j+1])
            {
                i++;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> n >> m >> h;
    
    for (int i = 1; i <= m; ++i)
    {
        int a,b;
        std::cin >> a >> b;
        ladder[a][b] = 1;
    }

    for (int i = 0; i < 4; ++i)
    {
        dfs(i,0);
    }
    
    if (ans == 987654321)
        ans = -1;

    std::cout << ans;
    
    return 0;
}
 