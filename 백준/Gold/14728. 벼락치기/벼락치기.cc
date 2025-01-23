#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, T; cin >> N >> T;
    N++;
    T++;
    vector<int> K(N);
    vector<int> S(N);
    vector dp(T, vector(N, 0));

    for (int i = 1; i < N; i++)
        cin >> K[i] >> S[i];
    
    for (int hp = 0; hp < T; hp++)
    {
        for (int i = 1; i < N; i++)
        {
            if (K[i] <= hp)
                dp[hp][i] = max(dp[hp - K[i]][i - 1] + S[i], dp[hp][i - 1]);
            else
                dp[hp][i] = dp[hp][i - 1];
        }
    }
    
    cout << dp[T - 1][N - 1];
    
    return 0;
}