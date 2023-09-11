#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N;
int arr[501][501];
int answer;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			if (i == N && arr[i][j] > answer) answer = arr[i][j];
		}
	}

	cout << answer;

	return 0;
}