#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> scores) 
{
    vector<int> wanho = scores[0];
    int wanho_sum = scores[0][0] + scores[0][1];
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b)
    {
        if (a[0] != b[0])
        {
            return a[0] > b[0];
        }
        return a[1] < b[1];
    });
    
    int max_b = -1;
    int answer = 1;
    for (const auto& score : scores)
    {
        int a = score[0];
        int b = score[1];
        
        if (a > wanho[0] && b > wanho[1]) return -1;
        
        if (max_b > b)
        {
            continue;
        }
        
        max_b = b;
        
        if (wanho_sum == a + b) continue;
        
        if (a + b > wanho_sum) answer++;
    }
    
    return answer;
}
