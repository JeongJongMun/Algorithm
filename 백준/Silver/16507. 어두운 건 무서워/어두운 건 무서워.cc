#include <bits/stdc++.h>
using namespace std;

int R, C, Q;

int picture[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> Q;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> picture[i][j];
			picture[i][j] += picture[i - 1][j] + picture[i][j - 1] - picture[i - 1][j - 1];
		}
	}

	int r1, c1, r2, c2;
	for (int i = 0; i < Q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (picture[r2][c2] + picture[r1 - 1][c1 - 1] - picture[r2][c1 - 1] - picture[r1 - 1][c2]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << endl;
	}

	return 0;
}