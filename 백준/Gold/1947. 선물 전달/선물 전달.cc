#include <vector>
#include <iostream>
using namespace std;


int main()
{
    int N; cin >> N;
    vector<long long> dp(N + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000000;

    cout << dp[N] << '\n';
    
    return 0;
}