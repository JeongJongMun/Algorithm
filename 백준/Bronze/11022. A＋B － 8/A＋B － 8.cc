#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B; cin >> A >> B;
		cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << '\n';
	}

	return 0;
}