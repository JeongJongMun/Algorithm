#include <vector>
#include <queue>
#include <iostream>


long long solution(int n, std::vector<int> works) 
{
    std::priority_queue<int> pq;
    
    for (const auto& work : works)
    {
        pq.push(work);
    }
    
    while (!pq.empty() && n > 0)
    {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        
        while (n > 0 && first > 0 && first >= second)
        {
            first--;
            n--;
        }
        
        if (first > 0)
        {
            pq.push(first);                    
        }
    }
    
    long long answer = 0;
    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        
        answer += first * first;
    }

    return answer;
}