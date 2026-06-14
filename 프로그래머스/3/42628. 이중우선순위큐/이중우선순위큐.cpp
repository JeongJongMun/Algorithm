#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

std::vector<int> solution(std::vector<std::string> operations) 
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    std::priority_queue<int> max_pq;
    std::unordered_map<int, int> count;
    
    for (const auto& op : operations)
    {
        char command = op[0];
        int num = std::stoi(op.substr(2, op.size()));
        if (command == 'I')
        {
            min_pq.push(num);
            max_pq.push(num);
            count[num]++;
        }
        else if (num == 1)
        {
            while (!max_pq.empty() && count[max_pq.top()] == 0)
            {
                max_pq.pop();
            }
            if (!max_pq.empty())
            {
                int num = max_pq.top();
                max_pq.pop();
                count[num]--;                
            }
        }
        else if (num == -1)
        {
            while (!min_pq.empty() && count[min_pq.top()] == 0)
            {
                min_pq.pop();
            }
            if (!min_pq.empty())
            {
                int num = min_pq.top();
                min_pq.pop();
                count[num]--;                
            }
        }
    }    

    while (!max_pq.empty() && count[max_pq.top()] == 0)
    {
        max_pq.pop();
    }
    while (!min_pq.empty() && count[min_pq.top()] == 0)
    {
        min_pq.pop();
    }
    std::vector<int> answer;
    
    // 653 -45
    // 654 -45
    
    int max_elem = max_pq.empty() ? 0 : max_pq.top();
    int min_elem = min_pq.empty() ? 0 : min_pq.top();
    
    answer.push_back(max_elem);
    answer.push_back(min_elem);
    
    return answer;
}