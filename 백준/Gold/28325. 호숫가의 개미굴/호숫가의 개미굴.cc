#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 개미굴의 수
int answer; // 정답

int main() {

	cin >> N;

	vector<int> room(N);

	for (int i = 0; i < N; i++) {
		cin >> room[i];
	}

	for (int i = 0; i < N; i++) {
		if (room[i] > 0) {
			answer += room[i];
			continue;
		}
		if (i == 0) {
			if (room[N - 1] >= 0 && room[(i + 1) % N] >= 0) {
				answer++;
				room[i] = -1;
			}
		}
		else {
			if (room[i - 1] >= 0 && room[(i + 1)% N] >= 0) {
				answer++;
				room[i] = -1;
			}
		}
		
	}

	cout << answer;

	return 0;
}
