#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][100001]; // [N][K]

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	// K = 최대 무게, limit = 현재 최대 무게
	for (int limit = 1; limit <= K; limit++) {
		// N = 물건 개수
		for (int i = 1; i <= N; i++) {
			// j번째 물건이 무거워서 못담음
			if (W[i] > limit) dp[i][limit] = dp[i - 1][limit];
			// j번째 물건을 담을 수 있음
			else dp[i][limit] = max(dp[i - 1][limit - W[i]] + V[i], dp[i - 1][limit]);
		}
	}

	cout << dp[N][K];

	return 0;
}