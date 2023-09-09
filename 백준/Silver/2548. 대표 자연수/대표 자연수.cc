#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;

int N; // 자연수의 개수
int answer = INT_MAX; // 답
int minGap = INT_MAX;

int main() {

	cin >> N;

	vector<int> numbers(N);

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.rbegin(), numbers.rend());

	for (int i = 0; i < N; i++) {
		int gap_sum = 0;

		for (int j = 0; j < N; j++) {
			gap_sum += abs(numbers[i] - numbers[j]);
		}

		if (gap_sum <= minGap) {
			answer = numbers[i];
			minGap = gap_sum;
		}
	}

	cout << answer;
	
	return 0;
}