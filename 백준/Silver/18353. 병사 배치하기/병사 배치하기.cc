#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n;
int answer;

int main() {

	cin >> n;
	
	vector<int> arr(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int k = 0; k < n; k++) {
		dp[k] = 1;
		for (int i = 0; i < k; i++) {
			if (arr[i] > arr[k]) {
				dp[k] = max(dp[k], dp[i] + 1);
			}
			if (answer < dp[k]) answer = dp[k];
		}
	}
	
	cout << n - answer;

	return 0;
}