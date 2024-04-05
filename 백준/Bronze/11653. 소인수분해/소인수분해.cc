#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << i << '\n';
		}
	}

	return 0;
}