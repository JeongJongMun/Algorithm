#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 애플 파이의 개수, 먹으려는 애플 파이 개수
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	vector<int> apple_pie(N + 1);

	int sum = 0, x;
	for (int i = 1; i < N + 1; i++) {
		cin >> x;
		sum += x;
		apple_pie[i] = sum;
	}

	int start = 0;
	int end = K;
	int answer = 0;
	for (; end < N + 1; end++, start++) {
		answer = max(answer, apple_pie[end] - apple_pie[start]);
	}

	// 애플 파이를 원형으로 배치한 부분 검사
	end = 1;
	for (; start < N; end++, start++) {
		answer = max(answer, apple_pie[N] - apple_pie[start] + apple_pie[end]);
	}

	cout << answer;

	return 0;
}