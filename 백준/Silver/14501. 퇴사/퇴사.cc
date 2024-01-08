#include <bits/stdc++.h>
using namespace std;

int t[16];
int p[16];
int ans[16];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		int tt = i + t[i];
		if (tt > N) ans[i] = ans[i + 1];
		else {
			// max(현재 상담하기, 현재 상담 안하기)
			ans[i] = max(ans[i + 1], ans[tt] + p[i]);
		}
	}

	cout << ans[0];

	return 0;
}