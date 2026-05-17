#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<vector<int>> signals) 
{
    // 신호등 주기(green + yellow + red)들이 담길 배열
    vector<int> signal_periods;
    
    // 반복해야 하는 횟수 = 신호등 주기들의 최소공배수
    int signal_lcm = 1;
    
    for (const auto& signal : signals)
    {
        int signal_period = signal[0] + signal[1] + signal[2];
        signal_periods.push_back(signal_period);
        signal_lcm = lcm(signal_period, signal_lcm);
    }

    // T = green + yellow + red
    // t초일 때, 주기 내 상대적인 위치는 (t-1) % T
    // if 0 <= x < green -> 초록불
    // if green <= x < green + yellow -> 노란불
    // if green + yellow <= x < green + yello + red -> 빨간불
    for (int t = 1; t <= signal_lcm; t++)
    {
        bool is_all_yellow = true;
        
        for (int i = 0; i < signals.size(); i++)
        {
            int T = signal_periods[i];
            int pos = (t - 1) % T;
            
            if (!(signals[i][0] <= pos && pos < signals[i][0] + signals[i][1]))
            {
                is_all_yellow = false;
                break;
            }
        }
        
        if (is_all_yellow)
        {
            return t;
        }
    }
    
    return -1;
}