#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M, N; cin >> M >> N;
	vector<int> v(N + 1);

	for (int i = 2; i <= sqrt(N); i++) {
		if (v[i] == 1) continue;
		for (int j = i * i; j <= N; j += i)
			v[j] = 1;
	}

	for (int i = M; i <= N; i++) {
		if (v[i] == 0 && i != 1) cout << i << '\n';
	}

	return 0;
}
