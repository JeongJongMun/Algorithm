#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(int coin, vector<int> cards) 
{
    int answer = 1;
    int n = cards.size();
    
    priority_queue<int, vector<int>, greater<int>> card_pairs;
    unordered_map<int, int> card_cost;
    set<int> hands;
    
    int i = 0;
    for (; i < n / 3; i++)
    {
        hands.insert(cards[i]);
        
        if (hands.find(n + 1 - cards[i]) != hands.end())
        {
            card_pairs.push(0);
        }
    }
    
    for (; i < n; i++)
    {
        hands.insert(cards[i]);
        card_cost[cards[i]] += 1;
        
        int pair = n + 1 - cards[i];
        if (hands.find(pair) != hands.end())
        {
            card_pairs.push(card_cost[cards[i]] + card_cost[pair]);
        }
        
        if (i % 2 == 0) continue;
        
        if (!card_pairs.empty())
        {
            int cost = card_pairs.top();
            card_pairs.pop();
            
            if (cost > coin)
            {
                break;
            }
                
            coin -= cost;
            answer++;
        }
        else
        {
            break;
        }
            
    }
    
    return answer;
}