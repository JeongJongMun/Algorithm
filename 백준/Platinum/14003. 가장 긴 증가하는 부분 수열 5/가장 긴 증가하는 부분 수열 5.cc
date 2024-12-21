#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> dp;
    vector<int> idx;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp.push_back(arr[0]);
    idx.push_back(0);
    
    for (int i = 1; i < N; i++)
    {
        if (dp.back() < arr[i])
        {
            idx.push_back(dp.size());
            dp.push_back(arr[i]);
        }
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            auto index = distance(dp.begin(), it);
            dp[index] = arr[i];
            idx.push_back(index);
        }
    }

    cout << dp.size() << '\n';

    vector<int> ans;
    int target = dp.size() - 1;
    for (int i = N - 1; i >= 0; i--)
    {
        if (idx[i] == target)
        {
            ans.push_back(arr[i]);
            target--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    
    return 0;
}