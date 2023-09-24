#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long answer;

int main() {
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int sum = v[i] + v[j];
			int left = lower_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
			int right = upper_bound(v.begin() + j + 1, v.end(), -sum) - v.begin();
			answer += right - left;
		}
	}

	cout << answer;

	return 0;
}