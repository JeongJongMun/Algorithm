#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	vector<int> cost(N);

	int max_cost = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		max_cost = max(max_cost, cost[i]);
	}
	
	cin >> M;

	int left = 1; // 0으로 하면 Division By Zero 런타임 에러 발생
	int right = max_cost;
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;


		for (auto i : cost) {
			sum += min(i, mid);
		}

		if (sum > M) {
			right = mid - 1;
		}

		else {
			answer = max(answer, mid);
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}