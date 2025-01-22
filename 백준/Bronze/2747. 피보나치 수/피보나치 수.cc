#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<long long> dp(N + 1, 0);
    dp[1] = 1;
    for (int i = 2; i < N + 1; i++)
        dp[i] = dp[i - 2] + dp[i - 1];

    cout << dp[N];
    
    return 0;
}