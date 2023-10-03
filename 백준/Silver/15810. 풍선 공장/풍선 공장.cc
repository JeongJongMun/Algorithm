#include <bits/stdc++.h>
using namespace std;

int N, M;
long long answer;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<int> staff(N);
	for (int i = 0; i < N; i++) {
		cin >> staff[i];
	}

	long long left = 1, right = 1000000000000;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (auto i : staff)
			cnt += mid / i;

		if (cnt >= M) {
			right = mid - 1;
			answer = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}
