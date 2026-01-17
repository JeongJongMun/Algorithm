#include <iostream>

struct info
{
    int number;
    bool bIsCalled = false;
};

info arr[5][5];
int n = 5;
int cnt = 3;

bool check()
{
    int bingo_count = 0;
    
    for (int i = 0; i < n; i++)
    {
        bool bIsBingo = true;
        for (int j = 0; j < n; j++)
        {
            if (!arr[i][j].bIsCalled)
            {
                bIsBingo = false;
                break;
            }
        }
        if (bIsBingo) bingo_count++;
    }
    
    for (int i = 0; i < n; i++)
    {
        bool bIsBingo = true;
        for (int j = 0; j < n; j++)
        {
            if (!arr[j][i].bIsCalled)
            {
                bIsBingo = false;
                break;
            }
        }
        if (bIsBingo) bingo_count++;
    }
    
    bool bIsBingo = true;
    for (int i = 0; i < n; i++)
    {
        if (!arr[i][i].bIsCalled)
        {
            bIsBingo = false;
            break;
        }
    }
    if (bIsBingo) bingo_count++;
    
    bIsBingo = true;
    for (int i = 4, j = 0; i >= 0 && j < n; i--, j++)
    {
        if (!arr[i][j].bIsCalled)
        {
            bIsBingo = false;
            break;
        }
    }
    if (bIsBingo) bingo_count++;
    
    if (bingo_count >= 3)
    {
        return true;
    }
    return false;
}

void call(int num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j].number == num)
            {
                arr[i][j].bIsCalled = true;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int number;
            std::cin >> number;
            info info { number };
            arr[i][j] = info;
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer++;
            int number;
            std::cin >> number;
            
            call(number);
            if (check())
            {
                std::cout << answer;
                return 0;
            }
            
        }
    }
    
    return 0;
}