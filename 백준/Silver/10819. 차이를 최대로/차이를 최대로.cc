#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N;
int answer;

int main() {

	cin >> N;
	vector<int> arr(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	do {
		int gap_sum = 0;
		for (int i = 0; i < N - 1; i++) {
			gap_sum += abs(arr[i] - arr[i + 1]);
		}
		if (gap_sum > answer) answer = gap_sum;

	} while (next_permutation(arr.begin(), arr.end()));

	cout << answer;

	return 0;
}