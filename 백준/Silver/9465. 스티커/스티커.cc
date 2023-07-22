#include <iostream>
#include <cmath>
using namespace std;

int dp[2][100001];
int t, n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				cin >> dp[j][k];

		for (int j = 0; j < n; j++) {
			if (j == 1) {
				dp[0][j] += dp[1][j - 1];
				dp[1][j] += dp[0][j - 1];
			}
			else {
				dp[0][j] += max(dp[1][j - 1], dp[1][j - 2]);
				dp[1][j] += max(dp[0][j - 1], dp[0][j - 2]);
			}
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}

	return 0;
}