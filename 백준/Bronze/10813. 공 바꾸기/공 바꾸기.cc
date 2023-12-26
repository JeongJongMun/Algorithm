#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) v[i] = i;

	for (int k = 0; k < M; k++) {
		int i, j; cin >> i >> j;
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}

	for (int i = 1; i <= N; i++) cout << v[i] << ' ';

	return 0;
}