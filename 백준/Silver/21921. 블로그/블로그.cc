#include <bits/stdc++.h>
using namespace std;

int N, X;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> X;

	vector<int> v(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	int max = 0, cnt = 0;
	for (int i = 1; i <= N - X + 1; ++i) {
		if (v[i + X - 1] - v[i - 1] > max) {
			max = v[i + X - 1] - v[i - 1];
			cnt = 1;
		}
		else if (v[i + X - 1] - v[i - 1] == max) {
			cnt++;
		}
	}

	if (max == 0) cout << "SAD" << '\n';
	else cout << max << '\n' << cnt << '\n';

	return 0;
}