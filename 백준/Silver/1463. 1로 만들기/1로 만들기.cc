#include <iostream>
#include <cmath>
using namespace std;
long long dp[1000001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}

	cout << dp[n];

	return 0;
}