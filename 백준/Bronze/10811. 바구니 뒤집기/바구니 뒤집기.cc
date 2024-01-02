#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M; cin >> N >> M;

	vector<int> v(N + 1);
	for (int i = 1; i < N + 1; i++) v[i] = i;

	for (int k = 0; k < M; k++) {
		int i, j; cin >> i >> j;
		reverse(v.begin() + i, v.begin() + j + 1);
	}

	for (int i = 1; i < N + 1; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}