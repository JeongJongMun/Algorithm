#include <bits/stdc++.h>
using namespace std;

// 팀 수, 카약 손상 팀 수, 여분 카약 있는 팀 수
int N, S, R;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> S >> R;
	vector<int> c(N + 1, 1);

	for (int i = 0; i < S; i++) {
		int x; cin >> x;
		c[x]--;
	}

	for (int i = 0; i < R; i++) {
		int x; cin >> x;
		c[x]++;
	}

	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) {
			if (c[i - 1] == 2) {
				c[i - 1]--;
				c[i]++;
			}
			else if (c[i + 1] == 2) {
				c[i + 1]--;
				c[i]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) cnt++;
	}
	cout << cnt;


	return 0;
}