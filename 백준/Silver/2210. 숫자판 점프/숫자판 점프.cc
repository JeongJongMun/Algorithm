#include <bits/stdc++.h>
using namespace std;

char arr[5][5];
set<string> numbers;

// 동서남북
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

void dfs(int a, int b, string number) {
	number += arr[a][b];
	if (number.size() >= 6) {
		numbers.insert(number);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = a + x[i];
		int ny = b + y[i];
		if (nx >= 0 and nx < 5 and ny >= 0 and ny < 5) {
			dfs(nx, ny, number);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, "");
		}
	}

	cout << numbers.size() << endl;

	return 0;
}