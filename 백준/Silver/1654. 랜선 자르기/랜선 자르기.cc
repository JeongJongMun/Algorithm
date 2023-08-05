#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	vector<int> lan(N);

	int max_lan = 0;
	for (int i = 0; i < N; i++) {
		cin >> lan[i];
		max_lan = max(max_lan, lan[i]);
	}

	long long left = 1;
	long long right = max_lan;
	int answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		// 랜선 자르기
		for (auto i : lan) {
			sum += i / mid;
		}

		// 랜선을 더 짧게 잘라야 함
		if (sum < M) {
			right = mid - 1;
		}
		// 더 긴 랜선으로 잘라도 가능한지 체크
		else {
			answer = max((long long)answer, mid);
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}