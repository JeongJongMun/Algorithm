#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> dp{ 0, 1 };

	int minValue;
	for (int i = 2; i < n + 1; i++) {
		minValue = 1e9;
		for (int j = 1; j < sqrt(i) + 1; j++) {
			if (i - pow(j, 2) >= 0)
				minValue = min(minValue, dp[i - pow(j, 2)]);
		}
		dp.push_back(minValue + 1);
	}

	cout << dp[n];

	return 0;
}