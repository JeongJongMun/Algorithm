#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= 2 * (n - 1) + 1; i++) {
		if (i <= n) {
			for (int j = 0; j < n - i; j++) cout << ' ';
			for (int j = 0; j < i * 2 - 1; j++) cout << '*';
		}

		else {
			for (int j = 0; j < i - n; j++) cout << ' ';
			for (int j = 0; j < (4 * n) - 1 - (2 * i); j++) cout << '*';
		}

		cout << '\n';
	}

	return 0;
}