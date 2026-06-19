#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int get_waiting_time(const vector<pair<int, int>>& reqs, int mentor_count)
{
    // 상담 종료 시간
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < mentor_count; i++)
    {
        pq.push(0);
    }
    
    int total_wait = 0;
    for (const auto& req : reqs)
    {
        int end_time = pq.top();
        pq.pop();
        
        int start = req.first;
        int duration = req.second;

        if (end_time > start)
        {
            total_wait += (end_time - start);
            pq.push(end_time + duration);
        }
        else
        {
            pq.push(start + duration);
        }
    }
    
    return total_wait;
}

int solution(int k, int n, vector<vector<int>> reqs) 
{
    // 시작시간, 상담시간
    vector<vector<pair<int, int>>> type_reqs(k + 1);
    for (const auto& req : reqs)
    {
        type_reqs[req[2]].push_back({req[0], req[1]});
    }
    
    int max_mentor_count = n - k + 1;
    vector<vector<int>> cost(k + 1, vector<int>(max_mentor_count + 1, 0));
    
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= max_mentor_count; j++)
        {
            cost[i][j] = get_waiting_time(type_reqs[i], j);
        }
    }
    
    vector<int> current_mentor(k + 1, 1);
    int remaining_mentor = n - k;
    
    while (remaining_mentor > 0)
    {
        int max_reduce = -1;
        int target_type = -1;
        
        for (int i = 1; i <= k; i++)
        {
            int current_m = current_mentor[i];
            
            if (current_m < max_mentor_count)
            {
                int reduce = cost[i][current_m] - cost[i][current_m + 1];
                if (reduce > max_reduce)
                {
                    max_reduce = reduce;
                    target_type = i;
                }
            }
        }
        
        if (max_reduce <= 0) break;
        
        current_mentor[target_type]++;
        remaining_mentor--;
    }
    
    
    int answer = 0;
    for (int i = 1; i <= k; i++)
    {
        answer += cost[i][current_mentor[i]];
    }
    
    
    return answer;
}