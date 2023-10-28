#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += P[i] * (N - i);
	}

	cout << ans;


	return 0;
}