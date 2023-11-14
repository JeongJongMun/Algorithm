#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	vector<int> dist(N - 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}

	bool isJump = false;
	int ans = 0, checkpoint, low = 0, high = 0;
	for (; high < N - 1 and low < N - 1;) {
		ans = max(ans, high - low);
		
		if (dist[high] <= K) high++;
		else {
			if (isJump) {
				low = checkpoint + 1;
				high = low;
				isJump = false;
			}
			else {
				isJump = true;
				checkpoint = high;
				high++;
			}
		}
	}

	cout << max(ans, high - low) + 1;

	return 0;
}