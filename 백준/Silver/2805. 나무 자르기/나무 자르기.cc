#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 나무의 수 N, 집으로 가져가려는 나무의 길이 M

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	vector<int> woods(N);

	for (int i = 0; i < N; i++) {
		cin >> woods[i];
	}

	sort(woods.begin(), woods.end());

	int left = 0;
	int right = woods[N - 1];
	int mid, answer = 0;
	long long sum;
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		//cout << "Mid: " << mid << endl;
		// 나무 자르기3
		for (auto i : woods) {
			if (i > mid) sum += i - mid;
		}

		if (sum == M) {
			answer = mid;
			break;
		}

		// 절단기의 높이 설정을 낮춰야 함
		if (sum < M) {
			right = mid - 1;
		}
		// 더 높은 높이 설정으로 가능한지 체크
		else if (sum > M) {
			answer = mid;
			left = mid + 1;
		}
	}

	cout << answer;

	return 0;
}