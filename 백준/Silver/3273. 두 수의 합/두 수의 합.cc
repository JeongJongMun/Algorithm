#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N, X, answer;

int main() {

	cin >> N;
	vector<int> arr(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> X;

	sort(arr.begin(), arr.end());

	for (int left = 0, right = N - 1; left < right;) {
		if (arr[left] + arr[right] == X) {
			answer++;
			right--;
		}
		if (arr[left] + arr[right] > X) right--;
		else if (arr[left] + arr[right] < X) left++;
	}

	cout << answer;

	return 0;
}