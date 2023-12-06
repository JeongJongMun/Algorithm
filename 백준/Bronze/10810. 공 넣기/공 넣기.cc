#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int N, M; cin >> N >> M;
	vector<int> v(N + 1);
	
	for (int s = 0; s < M; s++) {
		int i, j, k; cin >> i >> j >> k;
		for (int q = i; q <= j; q++) {
			v[q] = k;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << v[i] << ' ';
	}

	return 0;
}