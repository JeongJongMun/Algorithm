#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N, K;
int arr[10][10];
int answer = INT_MIN;

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> ingredient(N);
	for (int i = 0; i < N; i++)		ingredient[i] = i;

	vector<int> combination;
	for (int i = 0; i < N - K; i++) combination.push_back(0);
	for (int i = 0; i < K; i++)		combination.push_back(1);

	do {
		vector<int> selected;
		for (int i = 0; i < combination.size(); i++) {
			if (combination[i]) {
				selected.push_back(ingredient[i]);
			}
		}

		int taste = 0;
		for (int i = 0; i < K; i++) {
			for (int j = i + 1; j < K; j++) {
				taste += arr[selected[i]][selected[j]];
			}
		}
		if (answer < taste) answer = taste;

	} while (next_permutation(combination.begin(), combination.end()));

	cout << answer;

	return 0;
}