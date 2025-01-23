#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    N++;
    vector<int> A(N);
    vector<int> C(N);

    for (int i = 1; i < N; i++)
        cin >> A[i];

    int sumC = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> C[i];
        sumC += C[i];
    }
    sumC++;
    
    vector dp(sumC, vector(N, 0));

    for (int cost = 0; cost < sumC; cost++)
    {
        for (int i = 1; i < N; i++)
        {
            if (cost >= C[i])
                dp[cost][i] = max(dp[cost - C[i]][i - 1] + A[i], dp[cost][i - 1]);
            else
                dp[cost][i] = dp[cost][i - 1];
        }
    }

    for (int i = 0; i < sumC; i++)
    {
        if (dp[i][N - 1] >= M)
        {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}
