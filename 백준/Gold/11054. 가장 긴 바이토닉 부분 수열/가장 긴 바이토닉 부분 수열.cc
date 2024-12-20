#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector<int> arr(N);
    vector dp(N, vector (N, 1));
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        for (int left = i - 1; left >= 0; left--)
        {
            for (int k = i; left < k; k--)
                if (arr[left] < arr[k])
                    dp[i][left] = max(dp[i][left], dp[i][k] + 1);
        }

        for (int right = i + 1; right < N; right++)
        {
            for (int k = i; k < right; k++)
                if (arr[k] > arr[right])
                    dp[i][right] = max(dp[i][k] + 1, dp[i][right]);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int left_max = *max_element(dp[i].begin(), dp[i].begin() + i + 1);
        int right_max = *max_element(dp[i].begin() + i, dp[i].end());
        ans = max(ans, left_max + right_max - 1);
    }
    
    cout << ans << '\n';

    return 0;
}