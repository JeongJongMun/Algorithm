#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
using namespace std;

int arr[200000];
int cnt[100001];
int N, K, answer;

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int end = 0, start = 0; end < N; end++) {
		cnt[arr[end]]++;
		if (cnt[arr[end]] > K) {
			while (cnt[arr[end]] > K) {
				cnt[arr[start]]--;
				start++;
			}
		}
		answer = max(answer, end - start + 1);
	}

	cout << answer;

	return 0;
}