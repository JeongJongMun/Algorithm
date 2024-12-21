#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector arr(N, 0);
    vector dp(N, 1);
    vector prev(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    auto iter = max_element(dp.begin(), dp.end());
    auto idx = iter - dp.begin();
    

    vector<int> ans;
    for (int i = idx; i != -1; i = prev[i])
        ans.push_back(arr[i]);
    sort(ans.begin(), ans.end());

    cout << *iter << '\n';
    for (auto &elem : ans)
        cout << elem << ' ';
    
    return 0;
}