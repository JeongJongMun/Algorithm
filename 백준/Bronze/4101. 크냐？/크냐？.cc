#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 and b == 0) break;
		if (a > b) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}

	return 0;
}