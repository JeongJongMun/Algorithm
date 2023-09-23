#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;

int main() 
{
	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int left = 0, right = N - 1; left < right;) {
		if (v[left] + v[right] >= M) {
			left++; right--; answer++;
		}
		if (v[left] + v[right] < M) {
			left++;
		}
	}

	cout << answer;

	return 0;
}