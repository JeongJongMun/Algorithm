#include <bits/stdc++.h>
using namespace std;

int N, R, C, answer;

void Z(int y, int x, int size) {
	if (R == y and C == x) {
		cout << answer;
		return;
	}

	if (R >= y and R < y + size and C >= x and C < x + size) {
		// 1
		Z(y, x, size / 2);
		// 2
		Z(y, x + size / 2, size / 2);
		// 3
		Z(y + size / 2, x, size / 2);
		// 4
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else {
		answer += size * size;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> R >> C;

	Z(0, 0, (1 << N));

	return 0;
}