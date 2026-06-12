#include <vector>

int solution(std::vector<std::vector<int>> board, std::vector<std::vector<int>> skills) 
{
    int N = board.size();
    int M = board[0].size();
    
    std::vector<std::vector<int>> imos(N, std::vector<int>(M, 0));
    
    for (const auto& skill : skills)
    {
        int type = skill[0] == 1 ? -1 : 1;
        int r1 = skill[1];
        int c1 = skill[2];
        int r2 = skill[3];
        int c2 = skill[4];
        int degree = skill[5];

        imos[r1][c1] += degree * type;
        if (r2 + 1 < N && c2 + 1 < M) imos[r2 + 1][c2 + 1] += degree * type;
        if (c2 + 1 < M) imos[r1][c2 + 1] += -degree * type;
        if (r2 + 1 < N) imos[r2 + 1][c1] += -degree * type;        
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j - 1 >= 0) imos[i][j] += imos[i][j - 1];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i - 1 >= 0) imos[i][j] += imos[i - 1][j];
        }
    }
           
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int elem = board[i][j] + imos[i][j];
            if (elem >= 1)
            {
                answer++;
            }
        }
    }
    
    return answer;
}