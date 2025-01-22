#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int l, r;
    vector<pair<int, int>> arr(N);
    for (auto &[l, r] : arr)
        cin >> l >> r;
    
    sort(arr.begin(), arr.end());

    vector dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].second > arr[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << N - *max_element(dp.begin(), dp.end());
    
    return 0;
}