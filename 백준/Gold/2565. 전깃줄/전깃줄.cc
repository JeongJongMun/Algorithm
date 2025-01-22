#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int l, r;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
        arr[i] = make_pair(l, r);
    }

    sort(arr.begin(), arr.end());

    vector<int> rights;
    for (auto [left, right] : arr)
        rights.push_back(right);

    vector dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rights[i] > rights[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << N - *max_element(dp.begin(), dp.end());
    
    return 0;
}