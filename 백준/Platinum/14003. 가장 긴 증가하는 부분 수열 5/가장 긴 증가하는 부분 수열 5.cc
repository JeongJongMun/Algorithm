#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> dp;
    vector idx(N, 0);
    
    for (auto &elem : arr)
        cin >> elem;

    dp.push_back(arr[0]);
    
    for (int i = 1; i < N; i++)
    {
        auto iter = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (iter == dp.end())
        {
            idx[i] = dp.size();
            dp.push_back(arr[i]);
        }
        else
        {
            idx[i] = iter - dp.begin();
            *iter = arr[i];
        }
    }

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

    cout << dp.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    
    return 0;
}