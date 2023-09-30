#include <bits/stdc++.h>
using namespace std;

int M, N, K;
int arr[1001][1001][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	string x;
	for (int i = 1; i <= M; i++) {
		cin >> x;
		for (int j = 1; j <= N; j++) {
			switch (x[j - 1]) {
				case 'J':
					arr[i][j][0]++;
					break;
				case 'O':
					arr[i][j][1]++;
					break;
				case 'I':
					arr[i][j][2]++;
					break;
			}

			for (int k = 0; k < 3; k++) {
				arr[i][j][k] += arr[i - 1][j][k] + arr[i][j - 1][k] - arr[i - 1][j - 1][k];
			}
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = 0; j < 3; j++) {
			cout << arr[x2][y2][j] - arr[x1 - 1][y2][j] - arr[x2][y1 - 1][j] + arr[x1 - 1][y1 - 1][j] << " ";

		}
		cout << "\n";
	}

	return 0;
}