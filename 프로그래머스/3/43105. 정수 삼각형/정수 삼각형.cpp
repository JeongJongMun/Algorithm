#include <vector>

int max(int a, int b)
{
    return a > b ? a : b;
}

int solution(std::vector<std::vector<int>> t) 
{
    for (int i = 1; i < t.size(); i++)
    {
        for (int j = 0; j < t[i].size(); j++)
        {
            int left_parent = j - 1 >= 0 ? t[i - 1][j - 1] : 0;
            int right_parent = j != t[i].size() - 1 ? t[i - 1][j] : 0;
            t[i][j] = t[i][j] + max(left_parent, right_parent);
        }
    }
    
    int answer = 0;
    
    for (int i = 0; i < t[t.size() - 1].size(); i++)
    {
        answer = max(answer, t[t.size() - 1][i]);
    }
    
    
    return answer;
}