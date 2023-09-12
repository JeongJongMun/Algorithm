#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

// 0~N까지 N개를 더해서 K가 되는 경우의 수 구하기
// 덧셈의 순서가 다르면 다른 경우임 (1+2와 2+1은 다르고, 1+1과 1+1은 같음)

int N, K;
int dp[201][201]; // 행:K, 열:N

int main() {

	cin >> N >> K;

	// 한 개의 수로 N을 만드는 경우의 수는 모두 1
	for (int n = 0; n <= N; n++) {
		dp[1][n] = 1;
	}

	// K개의 수로 0을 만드는 경우의 수는 모두 1
	for (int k = 1; k <= K; k++) {
		dp[k][0] = 1;
	}
	
	for (int k = 2; k <= K; k++) {
		for (int n = 1; n <= N; n++) {
			dp[k][n] = (dp[k - 1][n] + dp[k][n - 1]) % 1000000000;
		}
	}

	cout << dp[K][N] << endl;

	return 0;
}