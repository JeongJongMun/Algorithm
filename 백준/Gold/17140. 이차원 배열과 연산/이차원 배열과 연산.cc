#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

int arr[101][101] = {};
int R_size = 3;
int C_size = 3;

struct Element
{
    int number;
    int count;

    Element(int num, int cnt) : number(num), count(cnt) {}

    bool operator<(const Element& other) const
    {
        if (count == other.count)
        {
            return number > other.number;
        }
        return count > other.count;
    }
};

void Print()
{
    for (int i = 1; i <= R_size; i++)
    {
        for (int j = 1; j <= C_size; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Sort_R()
{
    int new_arr[101][101] = {};
    int max_C_size = 0;

    for (int i = 1; i <= R_size; i++)
    {
        std::priority_queue<Element> pq;
        std::map<int, int> count_map;
        
        for (int j = 1; j <= C_size; j++)
        {
            if (arr[i][j] == 0) continue;
            count_map[arr[i][j]]++;
        }

        for (const auto& [number, count] : count_map)
        {
            pq.emplace(number, count);
        }

        int current_col = 1;
        while (!pq.empty())
        {
            Element elem = pq.top();
            pq.pop();
            
            if (current_col > 100) break;
            
            new_arr[i][current_col++] = elem.number;
            new_arr[i][current_col++] = elem.count;
        }
        
        max_C_size = std::max(max_C_size, current_col - 1);
    }
    
    memcpy(arr, new_arr, sizeof(arr));

    C_size = max_C_size;

    C_size = std::min(C_size, 100);
}

void Sort_C()
{
    int new_arr[101][101] = {};
    int max_R_size = 0;

    for (int i = 1; i <= C_size; i++)
    {
        std::priority_queue<Element> pq;
        std::map<int, int> count_map;
        
        for (int j = 1; j <= R_size; j++)
        {
            if (arr[j][i] == 0) continue;
            count_map[arr[j][i]]++;
        }

        for (const auto& [number, count] : count_map)
        {
            pq.emplace(number, count);
        }

        int current_row = 1;
        while (!pq.empty())
        {
            Element elem = pq.top();
            pq.pop();
            
            if (current_row > 100) break;
            
            new_arr[current_row++][i] = elem.number;
            new_arr[current_row++][i] = elem.count;
        }
        
        max_R_size = std::max(max_R_size, current_row - 1);
    }
    
    memcpy(arr, new_arr, sizeof(arr));

    R_size = max_R_size;

    R_size = std::min(R_size, 100);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int r, c, k;
    std::cin >> r >> c >> k;

    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
             std::cin >> arr[i][j];
        }
    }

    int time = 0;
    while (time <= 100)
    {
        if (arr[r][c] == k)
        {
            std::cout << time << '\n';
            return 0;
        }

        if (time == 100) break; 
        
        if (R_size >= C_size)
        {
            Sort_R();
        }
        else
        {
            Sort_C();
        }
        
        time++;
    }

    std::cout << -1 << '\n';

    return 0;
}