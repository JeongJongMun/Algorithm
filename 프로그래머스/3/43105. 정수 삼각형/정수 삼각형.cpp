#include <iostream>
#include <string>
#include <vector>

int max(int a, int b)
{
    return a > b ? a : b;
}

void print(const std::vector<std::vector<int>>& triangle)
{
    for (const auto& row : triangle)
    {
        for (const auto& elem : row)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int solution(std::vector<std::vector<int>> triangle) 
{
    /*
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    */
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int left_parent = j - 1 >= 0 ? triangle[i - 1][j - 1] : 0;
            int right_parent = j != triangle[i].size() - 1 ? triangle[i - 1][j] : 0;
            triangle[i][j] = triangle[i][j] + max(left_parent, right_parent);
        }
    }
    
    int answer = 0;
    
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
    {
        answer = max(answer, triangle[triangle.size() - 1][i]);
    }
    
    
    return answer;
}