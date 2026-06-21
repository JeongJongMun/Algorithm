#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b)
     {
         if (a[0] != b[0])
         {
             return a[0] > b[0];         
         }
         return a[1] > b[1];
     });

    int enter = 0;
    int index = 0;
    int n = routes.size();
    
    while (true)
    {
        enter = routes[index][0];
        answer++;
                
        while (index < n - 1 && routes[index][1] >= enter)
        {
            index++;
        }
        
        if (index >= n - 1)
        {
            if (routes[index][1] < enter) answer++;            
            break;
        }
    }
    
    return answer;
}