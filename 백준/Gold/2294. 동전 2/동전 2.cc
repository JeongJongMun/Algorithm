#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;

	vector<int> coins;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		coins.push_back(x);
	}

	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int coin = coins[i];
		for (int j = 0; j <= k; j++)
		{
			if (j - coin < 0) continue;

			if (j - coin != 0 && dp[j - coin] == 0) continue;

			if (dp[j] == 0)
			{
				dp[j] = dp[j - coin] + 1;
			}
			else
			{
				dp[j] = min(dp[j], dp[j - coin] + 1);
			}
		}
	}

	int res = (dp[k] != 0) ? dp[k] : -1;

	cout << res;

	return 0;
}
