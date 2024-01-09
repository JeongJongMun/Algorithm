#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int temp_sum = 0, cnt = 0, last_num = 0, last_idx = 0;
	int N, M; cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0) last_num = arr[i];
	}

	for (int i = 0; i < N; i++) {
		temp_sum += arr[i];
		while (temp_sum >= M) {
			if (temp_sum == M) cnt++;
			temp_sum -= last_num;
			last_idx++;
			last_num = arr[last_idx];
		}
	}

	cout << cnt;

	return 0;
}