#include <iostream>
#include <string>
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
    int answer = 0;
    int signal_count = signals.size();
    
    // 신호등 주기(green + yellow + red)들이 담길 배열
    vector<int> signal_periods;
    
    for (const auto& signal : signals)
    {
        // 신호등 주기 합
        int signal_period = 0;
        for (const auto& color : signal)
        {
            signal_period += color;
        }
        signal_periods.push_back(signal_period);
    }
    
    // 반복해야 하는 횟수 = 신호등 주기들의 최소공배수
    int signal_lcm = 1;
    for (const auto& signal_period : signal_periods)
    {
        signal_lcm = lcm(signal_period, signal_lcm);
    }
    
    // T = green + yellow + red
    // t초일 때, 주기 내 상대적인 위치는 (t-1) % T
    // if 0 <= x < green -> 초록불
    // if green <= x < green + yellow -> 노란불
    // if green + yellow <= x < green + yello + red -> 빨간불
    for (int t = 1; t <= signal_lcm; t++)
    {
        bool isThisTimeAllYellow = true;
        
        for (int i = 0; i < signal_count; i++)
        {
            int T = signal_periods[i];
            int pos = (t - 1) % T;
            
            bool isYellow = signals[i][0] <= pos && pos < signals[i][0] + signals[i][1];
            if (!isYellow)
            {
                isThisTimeAllYellow = false;
                break;
            }
        }
        
        if (isThisTimeAllYellow)
        {
            return t;
        }
    }
    
    return -1;
}