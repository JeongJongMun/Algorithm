#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int arr[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1] [j - 1];
		}
	}

	int i, j, x, y;
	cin >> K;
	for (int q = 0; q < K; q++) {
		cin >> i >> j >> x >> y;
		cout << arr[x][y] + arr[i - 1][j - 1] - arr[x][j - 1] - arr[i - 1][y] << "\n";
	}

	return 0;
}