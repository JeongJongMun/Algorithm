#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <tuple>
using namespace std;

#define LL long long 

int N;
int arr[33][33];
tuple<LL, LL, LL> dp[33][33];
// tuple: 각각 -(first) \(second) |(third) 로 올 수 있는 경우의 수
// dp[i][j].fisrt = dp[i][j-1].first + dp[i][j-1].second (-는 이전단계에서 |일때 올 수 없음)
// dp[i][j].second = dp[i-1][j-1].first + dp[i-1][j-1].second + dp[i-1][j-1].third (\는 모든 경우에서 올 수 있음)
// dp[i][j].third = dp[i-1][j].second + dp[i-1][j].third (|는 이전단계에서 -일때 올 수 없음)

// 벽
// dp[i][j-1]이 벽이라면 - 방향으로 올 수 없음
// dp[i-1][j]이 벽이라면 | 방향으로 올 수 없음
// dp[i-1][j-1] or dp[i-1][j] or dp[i][j-1]이 벽이라면 \ 방향으로 올 수 없음
int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	// DP
	dp[1][2] = make_tuple(1, 0, 0);
	LL first, second, third;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) continue;
			if (arr[i][j - 1] == 0) {
				tie(first, second, third) = dp[i][j - 1];
				get<0>(dp[i][j]) += first + second;
			}
			if (arr[i - 1][j - 1] == 0 && arr[i][j - 1] == 0 && arr[i - 1][j] == 0) {
				tie(first, second, third) = dp[i - 1][j - 1];
				get<1>(dp[i][j]) += first + second + third;
			}
			if (arr[i - 1][j] == 0) {
				tie(first, second, third) = dp[i - 1][j];
				get<2>(dp[i][j]) += second + third;
			}
		}
	}


	tie(first, second, third) = dp[N][N];
	cout << first + second + third;
	
	return 0;
}