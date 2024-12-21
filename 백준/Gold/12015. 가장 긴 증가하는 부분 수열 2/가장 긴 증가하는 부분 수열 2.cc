#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> arr(N);
    vector<int> dp;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp.push_back(arr[0]);
    
    for (int i = 1; i < N; i++)
    {
        if (dp.back() < arr[i])
            dp.push_back(arr[i]);
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
            auto idx = distance(dp.begin(), it);
            dp[idx] = arr[i];
        }

    }

    cout << dp.size() << '\n';
    
    return 0;
}