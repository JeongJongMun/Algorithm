#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, answer; cin >> N >> M;

	vector<int> bluray(N);

	int right = 0;
	for (int i = 0; i < N; i++) {
		cin >> bluray[i];
		right += bluray[i];
	}

	int left = *max_element(bluray.begin(), bluray.end());
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int bluray_sum = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {

			if (bluray_sum + bluray[i] > mid) {
				bluray_sum = 0;
				cnt++;
			}
			bluray_sum += bluray[i];
		}
		if (bluray_sum != 0) cnt++;

		if (cnt > M) {
			left = mid + 1;
		}
		else if (cnt <= M) {
			right = mid - 1;
			answer = mid;
		}
	}

	cout << answer;
	return 0;
}