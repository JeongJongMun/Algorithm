#include <string>
#include <vector>

void hanoi(std::vector<std::vector<int>>& answer, int n, int from, int tmp, int to)
{
    if (n == 1)
    {
        answer.push_back({from, to});
        return;
    }
    hanoi(answer, n - 1, from, to, tmp);
    answer.push_back({from, to});
    hanoi(answer, n - 1, tmp, from, to);
}

std::vector<std::vector<int>> solution(int n) 
{
    std::vector<std::vector<int>> answer;
    
    hanoi(answer, n, 1, 2, 3);
    
    return answer;
}