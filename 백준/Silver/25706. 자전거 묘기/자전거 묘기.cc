#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> dp(N);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		int jump;
		if (v[i] >= 1)	jump = v[i] + 1;
		else			jump = 1;

		if (i + jump >= N) {
			dp[i] = 1;
		}
		else {
			dp[i] = dp[i + jump] + 1;
		}
	}

	for (auto i : dp) {
		cout << i << " ";
	}

	return 0;
}