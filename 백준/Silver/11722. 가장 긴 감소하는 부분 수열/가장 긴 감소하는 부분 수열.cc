#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    vector<int> arr(N);
    vector dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}