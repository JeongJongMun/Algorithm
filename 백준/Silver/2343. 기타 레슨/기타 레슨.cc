#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, answer = 0; 
	cin >> N >> M;

	vector<int> bluray(N);

	for (int i = 0; i < N; i++) {
		cin >> bluray[i];
	}

	int left = *max_element(bluray.begin(), bluray.end());
	int right = accumulate(bluray.begin(), bluray.end(), 0);
	while (left <= right) {
		int mid = (left + right) / 2;
		int bluray_sum = 0;
		int cnt = 0;

		for (auto i : bluray) {
			if (bluray_sum + i > mid) {
				bluray_sum = 0;
				cnt++;
			}
			bluray_sum += i;
		}

		if (bluray_sum != 0) cnt++;

		if (cnt > M) left = mid + 1;
		else right = mid - 1;
	}

	cout << left;

	return 0;
}