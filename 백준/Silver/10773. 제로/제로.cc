#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	stack<int> s;
	
	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int n; cin >> n;
		if (n == 0) s.pop();
		else s.push(n);
	}

	long long ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	cout << ans;

	return 0;
}