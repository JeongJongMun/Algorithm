#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = 0;
	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		n += pow(x, 2);
	}

	cout << n % 10;
	return 0;
}