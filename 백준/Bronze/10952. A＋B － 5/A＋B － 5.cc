#include <bits/stdc++.h>
using namespace std;

int A, B;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		cin >> A >> B;
		if (!A and !B) break;
		cout << A + B << '\n';
	}

	return 0;
}