#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <climits>

int n, m, k;
int answer = INT_MAX;

struct rotation
{
    int r;
    int c;
    int s;
};

void Rotate(std::vector<std::vector<int>>& array, rotation operation)
{
    int r = operation.r;
    int c = operation.c;
    int s = operation.s;
    
    for (int i = 1; i <= s; i++)
    {
        int top = r - i - 1;
        int bottom = r + i - 1;
        int left = c - i - 1;
        int right = c + i - 1;
        
        int temp = array[top][left];
        
        for (int row = top; row < bottom; row++)
        {
            array[row][left] = array[row + 1][left];
        }
        for (int column = left; column < right; column++)
        {
            array[bottom][column] = array[bottom][column + 1];
        }
        for (int row = bottom; row > top; row--)
        {
            array[row][right] = array[row - 1][right];
        }
        for (int column = right; column > left; column--)
        {
            array[top][column] = array[top][column - 1];
        }
        
        array[top][left + 1] = temp;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    
    std::cin >> n >> m >> k;
    std::vector arr(n, std::vector<int>(m));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    
    std::vector<int> order;
    for (int i = 0; i < k; i++)
    {
        order.push_back(i);
    }
    
    std::vector<rotation> operations;
    int r, c, s;
    for (int i = 0; i < k; i++)
    {
        std::cin >> r >> c >> s;
        operations.push_back({r, c, s});
    }

    do
    {
        auto temp_arr = arr;
        for (int idx : order)
        {
            auto op = operations[idx];
            Rotate(temp_arr, op);
        }
        
        for (const auto& row : temp_arr)
        {
            int sum = std::accumulate(row.begin(), row.end(), 0);
            answer = std::min(answer, sum);
        }
    }
    while (std::next_permutation(order.begin(), order.end()));
    
    std::cout << answer;
    
    return 0;
}