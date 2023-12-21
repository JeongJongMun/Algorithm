#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	float trim = round(n * 0.15);
	float ans = 0;
	for (int i = trim; i < n - trim; i++) {
		ans += v[i];
	}

	if (n == 0) cout << 0;
	else cout << round(ans / (n - trim - trim)) << '\n';

	return 0;
}
