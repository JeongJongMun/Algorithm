#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string str; cin >> str;

	unsigned long long ans = 0;

	for (int i = 0; i < n; i++) {
		ans += (str[i] - 'a' + 1) * pow(31, i);
	}

	cout << ans;

	return 0;
}