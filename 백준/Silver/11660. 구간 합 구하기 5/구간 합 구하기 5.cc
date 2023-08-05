#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int arr[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 표의 크기 N, 합을 구하는 횟수 M
	cin >> N >> M; 

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> arr[i][j];
		}
	}

	// 누적합 구하기
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1] [j - 1];
		}
	}

	// 출력
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] + arr[x1 - 1][y1 - 1] - arr[x2][y1 - 1] - arr[x1 - 1][y2] << "\n";
	}

	return 0;
}