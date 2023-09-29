#include <bits/stdc++.h>
using namespace std;

int N, H;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> H;
	vector<int> top(H + 2); // 짝수 - 종유석
	vector<int> bottom(H + 2); // 홀수 - 석순

	int length;
	for (int i = 1; i <= N; i++) {
		cin >> length;
		if (i % 2 == 0) top[H - length + 1]++;
		else bottom[length]++;
	}

	for (int i = 1; i <= H; i++) {
		top[i] += top[i - 1];
		bottom[H - i + 1] += bottom[H - i + 2];
	}

	int min = INT_MAX;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {
		if (top[i] + bottom[i] < min) {
			min = top[i] + bottom[i];
			cnt = 1;
		}
		else if (top[i] + bottom[i] == min) cnt++;

	}

	cout << min << " " << cnt;

	return 0;
}