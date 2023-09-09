#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N, M, B;
int arr[500][500];
int answer_time = INT_MAX;
int answer_height;

int main() {

	cin >> N >> M >> B;

	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max) max = arr[i][j];
			if (arr[i][j] < min) min = arr[i][j];
		}
	}

	for (int height = min; height <= max; height++) {
		int time = 0;
		int block = B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > height) {
					time += abs(arr[i][j] - height) * 2;
					block += abs(arr[i][j] - height);
				}
				else if (arr[i][j] < height) {
					time += abs(arr[i][j] - height);
					block -= abs(arr[i][j] - height);
				}
			}
		}

		if (answer_time >= time && block >= 0) {
			answer_time = time;
			answer_height = height;
		}

	}

	cout << answer_time << " " << answer_height;

	return 0;
}