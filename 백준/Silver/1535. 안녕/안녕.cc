#include <algorithm>
#include <vector>
#include <iostream>
#define HP 101
using namespace std;

int main()
{
    int N; cin >> N;
    N++;
    vector<int> H(N);
    vector<int> P(N);
    vector dp(HP, vector(N, 0));

    for (int i = 1; i < N; i++)
        cin >> H[i];
    
    for (int i = 1; i < N; i++)
        cin >> P[i];
    
    for (int hp = 0; hp < HP; hp++)
    {
        for (int i = 1; i < N; i++)
        {
            if (H[i] < hp)
                dp[hp][i] = max(dp[hp - H[i]][i - 1] + P[i], dp[hp][i - 1]);
            else
                dp[hp][i] = dp[hp][i - 1];
        }
    }
    
    cout << dp[HP - 1][N - 1];
    
    return 0;
}