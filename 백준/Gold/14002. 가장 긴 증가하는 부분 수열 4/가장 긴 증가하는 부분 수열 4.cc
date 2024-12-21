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
    vector<vector<int>> li(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        li[i].push_back(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    li[i].clear();
                    for (auto &elem : li[j])
                        li[i].push_back(elem);
                    li[i].push_back(arr[i]);
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    auto iter = max_element(dp.begin(), dp.end());
    auto idx = iter - dp.begin();
    sort(li[idx].begin(), li[idx].end());
    
    cout << *iter << '\n';
    for (auto i : li[idx])
        cout << i << ' ';
    
    return 0;
}