#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N, M; // 0~N 도시, M 이내에 이동
int dp[1001][1001];

int main() {

	cin >> N >> M;
	
	vector<int> dist(N + 1);
	vector<int> weather(M);

	// 입력
	for (int i = 1; i <= N; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> weather[i];
	}


	// 전처리
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < i - 1; j++) {
			dp[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < M; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		dp[1][i] = dist[1] * weather[i];
	}


	// DP
	for (int i = 2; i <= N; i++) {
		for (int j = i - 1; j < M; j++) {
			int min_dist = INT_MAX;
			for (int k = 0; k < j; k++) {
				if (dp[i - 1][k] < min_dist) min_dist = dp[i - 1][k];
			}
			dp[i][j] = dist[i] * weather[j] + min_dist;
		}
	}

	//for (int i = 0; i <= N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	int answer = INT_MAX;
	for (int i = 0; i < M; i++) {
		if (dp[N][i] < answer) answer = dp[N][i];
	}

	cout << answer;

	return 0;
}