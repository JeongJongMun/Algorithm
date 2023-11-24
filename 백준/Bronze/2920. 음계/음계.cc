#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> v(8);

	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}

	if (v[0] == 1) {
		for (int i = 1; i <= 8; i++) {
			if (v[i - 1] != i) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}
	else if (v[0] == 8) {
		for (int i = 1; i <= 8; i++) {
			if (v[8 - i] != i) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}
	else cout << "mixed";

	return 0;
}