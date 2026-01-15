#include <iostream>

char board[200][200];
int count[200][200];

int r, c, n;

void Bomb(int i, int j)
{
    board[i][j] = '.';
    if (i + 1 < r)
    {
        board[i + 1][j] = '.';
    }
    if (i - 1 >= 0)
    {
        board[i - 1][j] = '.';
    }
    if (j + 1 < c)
    {
        board[i][j + 1] = '.';
    }
    if (j - 1 >= 0)
    {
        board[i][j - 1] = '.';
    }
}

void Count()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (count[i][j] > 0)
            {
                count[i][j]--;
                if (count[i][j] == 0)
                {
                    Bomb(i, j);
                }
            }
        }
    }
}

void Fill()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = 'O';
                count[i][j] = 3;
            }
            else if (board[i][j] == 'O')
            {
                count[i][j]--;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> r >> c >> n;
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 'O')
            {
                count[i][j] = 2;
            }
        }
    }
    
    int timer = 1;
    while (timer < n)
    {
        if (timer < n)
        {
            Fill();
            timer++;
        }
        if (timer < n)
        {
            Count();
            timer++;
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
    
    return 0;
}