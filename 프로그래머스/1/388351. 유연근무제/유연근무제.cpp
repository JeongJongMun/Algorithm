#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
    int n = schedules.size();
    
    // 출근 인정 시각 계산
    for (int i = 0; i < n; i++)
    {
        int temp = schedules[i] + 10;
        // 60분을 넘길 경우 hour로 변환
        if (temp % 100 >= 60)
        {
            temp = ((temp / 100) * 100) + 100 + ((temp % 100) % 60);
        }
        schedules[i] = temp;
    }
    
    int answer = 0;
    
    for (int i = 0; i < n; i++)
    {
        bool is_fail = false;
        int schedule = schedules[i];

        for (int j = 0; j < 7; j++)
        {
            int day = (startday + j) % 7;
            if (day == 6 || day == 0) continue;
            
            int timelog = timelogs[i][j];
            
            if (schedule < timelog)
            {
                is_fail = true;
                break;
            }
        }
        
        if (!is_fail)
        {
            answer++;
        }
    }
    
    
    return answer;
}